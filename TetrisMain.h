/***************************************************************
 * Name:      TetrisMain.h
 * Purpose:   Defines Application Frame
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-15
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#ifndef TETRISMAIN_H
#define TETRISMAIN_H

//(*Headers(TetrisFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class TetrisFrame: public wxFrame
{
    public:

        TetrisFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~TetrisFrame();

    private:

        //(*Handlers(TetrisFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(TetrisFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(TetrisFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TETRISMAIN_H
