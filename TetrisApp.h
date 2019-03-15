/***************************************************************
 * Name:      TetrisApp.h
 * Purpose:   Defines Application Class
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-15
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#ifndef TETRISAPP_H
#define TETRISAPP_H

#include <wx/app.h>

class TetrisApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // TETRISAPP_H
