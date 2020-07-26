#pragma once

#include <wx/wx.h>

class myMain : public wxFrame
{

public:
    myMain();
    ~myMain();
    void OnButtonClicked(wxCommandEvent &evt);

public:
    int nHeight = 10;
    int nWidth = 10;
    wxButton ** btn; 

    //mines
    int *nField = nullptr;
    bool bFirstClick = true;

};

