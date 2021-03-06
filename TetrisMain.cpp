/***************************************************************
 * Name:      TetrisMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-15
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:   GNU General Public License 3.0
 **************************************************************/

#include "wx_pch.h"
#include "TetrisMain.h"

#include <wx/msgdlg.h>

//(*InternalHeaders(TetrisFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(TetrisFrame)
const long TetrisFrame::idMenuQuit = wxNewId();
const long TetrisFrame::idMenuAbout = wxNewId();
const long TetrisFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TetrisFrame,wxFrame)
    //(*EventTable(TetrisFrame)
    //*)
END_EVENT_TABLE()

TetrisFrame::TetrisFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(TetrisFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TetrisFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TetrisFrame::OnAbout);
    //*)
    StatusBar1 = CreateStatusBar();
    StatusBar1->SetStatusText(wxT("0"));
    board = new Board(this);
    board->SetFocus();
    board->Start();
}

TetrisFrame::~TetrisFrame()
{
    //(*Destroy(TetrisFrame)
    //*)
    delete board;
}

void TetrisFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void TetrisFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
