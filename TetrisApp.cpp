/***************************************************************
 * Name:      TetrisApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-15
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "TetrisApp.h"

//(*AppHeaders
#include "TetrisMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(TetrisApp);

bool TetrisApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	TetrisFrame* Frame = new TetrisFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
