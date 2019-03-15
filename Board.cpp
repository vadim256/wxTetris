/***************************************************************
 * Name:      Board.cpp
 * Purpose:   The canvas on which the player will act
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-15
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:   GNU General Public License 3.0
 **************************************************************/

#include "Board.h"

Board::Board(wxFrame * parent)
try : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_DEFAULT),
  timer(new wxTimer(this, 1)), curShape(), isStarted(false), isPaused(false), 
  isFallingFinished(false), curX(0), curY(0), numLinesRemoved(0)
{
    m_StatusGame = parent->GetStatusBar();
    this->ClearBoard();
    this->Connect(wxEVT_PAINT, wxPainEventHandler(Board::OnPaint));
    this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(Board::OnKeyDown));
    this->Connect(wxEVT_TIMER, wxCommandEventHandler(Board::OnTimer));
}
catch(...){
    throw;
}

Board::~Board(){
    delete timer;
}

void Board::Start(){
    if(isPaused) return;
    isStarted = true;
    isFallingFinished = false;
    numLinesRemoved = 0;
    this->ClearBoard();
    this->NewPiece();
    timer->Start(300);
}

void Board::Pause() {
    if(!isStarted)
        return;
    isPaused = !isPaused;
    if(isPaused){
        timer->Stop();
        m_StatusGame->SetStatusText(wxT("paused"));
    } else {
        timer->Start(300);
        wxString line;
        line.Printf(wxT("%d"), numLinesRemoved);
        m_StatusGame->SetStatusText(line);
    }
    Refresh();
}


void Board::LinesRemovedChanged() {

}

Shape::Tetrominoes & Board::ShapeAt(int x, int y){
    return board[y*BoardWidth+x];
}

int Board::SquareWidth() const {
    this->GetClientSize().GetWidth()/BoardWidth;
}

int Board::SquareHeight() const {
    this->GetClientSize().GetHeight()/BoardHeight;
}

void Board::ClearBoard(){
    for(auto & shape : board)
        shape = Tetrominoes::NoShape;
}
void Board::DropDown() {

}

void Board::OneLineDown(){

}

void Board::PieceDropped(){

}

void Board::RemoveFullLines(){

}

void Board::NewPiece(){

    curPiece.SetRandomShape();
    curX = BoardWidth / 2 + 1;
    curY = BoardHeight - 1 + curPiece.MinY();
    if(!TryMove(curPiece, curX, curY)){
        curPiece.SetShape(Tetrominoes::NoShape);
        timer->Stop();
        isStarted = false;
        m_StatusGame->SetStatusText(wxT("game over"));
    }
}  

bool Board::TryMove(const Shape & newPiece, int newX, int newY){
    for(int i = 0; i < 4; ++i){
        int x = newX + newPiece.x(i);
        int y = newY + newPiece.y(i);
        if(x < 0 || x >= BoardWidth || y < 0 || y >= BoardHeight)
            return false;
        if(ShapeAt(x,y) != NoShape)
            return false;
    }
    curPiece = newPiece;
    curX = newX;
    curY = newY;
    Refresh();

    return true;
}


void Board::OnTimer(wxCommadnEvent & event){
    if(isFallingFinished){
        isFallingFinished = false;
        NewPiece();
    } else {
        OneLineDown()
    }
}

void Board::OnPaint(wxPaintEvent & event){

    wxPaintDC dc(this);
    wxSize size = GetClientSize();
    int boardTop = size.GetHeight() - BoardHeight * SquareHeight();

    for(int i = 0; i < BoardHeight; ++i){
        for(int j = 0; j < BoardWidth; ++j){
            Tetrominoes shape = ShapeAt(j, BoardHeight - i -1);
            if(shape != Tetrominoes::NoShape){
                DrawSquare(dc,0 + j * SquareWidth(), boardTop + i * SquareHeight(), shape);
            }
        }
    }
    if(curPiece.GetShape() != Tetrominoes::NoShape){
        for(int i = 0; i < 4; ++i){
            int x = curX + curPiece.x(i);
            int y = curY - curPiece.y(i);
            DrawSquare(dc, 0 + x * SquareWidth(), 
                       boardTop * (BoardHeight() - y - 1) * SquareHeight(),
                       curPiece.GetShape()
            );
        }
    }
}

void Board::DrawSquare(wxPaintDC & dc, int x, int y, Shape::Tetrominoes shape){

}

void Board::OnKeyDown(wxKeyEvent & event){

}