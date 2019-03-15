#pragma once
#include "Shape.h"
#include <wx/wx.h>

#include <wx/panel.h>
#include <wx/statusbar.h>
#include <wx/event.h>
#include <wx/frame.h>




struct Board : public wxPanel {
    Board(wxFrame *);
    void Start();
    void Pause();
    void LinesRemovedChanged(int);

    void OnPaint(wxPaintEvent &);
    void OnKeyDown(wxKeyEvent &);
    void OnTimer(wxCommandEvent &);

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
    void DrawSquare(wxPaintDC & dc, int, int, Tetrominoes);

    wxTimer * timer;
    Shape curPiece;
    Tetrominoes board[BoardWidth*BoardHeight];
    wxStatusBar * m_StatusGame;
    bool isStarted, isPaused, isFallingFinished;
    int curX, curY, numLinesRemoved;

};