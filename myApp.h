#pragma once

#include <wx/wx.h>
#include "myMain.h"

class myApp : public wxApp
{
    public:
        myApp();
        ~myApp();
    private:
        myMain * myFrame = nullptr;

    public: 
        virtual bool OnInit();
};