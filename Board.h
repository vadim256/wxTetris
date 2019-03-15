/***************************************************************
 * Name:      Board.h
 * Purpose:   The canvas on which the player will act
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-15
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:   GNU General Public License 3.0
 **************************************************************/

#pragma once

#include "Shape.h"
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/event.h>
#include <wx/dcclient.h>
#include <wx/timer.h>


struct Board : public wxPanel {
    Board() = default;
    explicit Board(wxFrame *);
    ~Board();
    
    void Start();
    void Pause();
    void LinesRemovedChanged(int);

    void OnPaint(wxPaintEvent &);
    void OnKeyDown(wxKeyEvent &);
    void OnTimer(wxCommandEvent &);
    using Shape::Tetrominoes;

private:
    enum : unsigned {
        BoardWidth = 10, BoardHeight = 22
    };

    Tetrominoes & ShapeAt(int, int);
    int SquareWidth() const;
    int SquareHeight() const;

    void ClearBoard();
    void DropDown();
    void OneLineDown();
    void PieceDropped();
    void RemoveFullLines();
    void NewPiece();
    bool TryMove(const Shape &, int, int);
    void DrawSquare(wxPaintDC &, int, int, Tetrominoes);

    wxTimer * timer;
    Shape curPiece;
    bool isStarted, isPaused, isFallingFinished;
    int curX, curY, numLinesRemoved;
    
    Tetrominoes board[BoardWidth*BoardHeight];
    wxStatusBar * m_StatusGame;

};