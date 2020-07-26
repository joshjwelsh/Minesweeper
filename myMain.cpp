#pragma once

#include "myMain.h"

myMain::myMain() : wxFrame(nullptr, wxID_ANY, "Josh's - MineSweeper ",wxPoint(30,30), wxSize(800,600))
{
    btn = new wxButton *[nWidth * nHeight];
    nField = new int[nWidth * nHeight];
    
    wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
    wxGridSizer *grid = new wxGridSizer(nWidth, nHeight, 0, 0);

    for (int i = 0; i < nWidth; i++)
    {
        for (int k = 0; k < nHeight; k++)
        {
            btn[k * nWidth + i] = new wxButton(this, 10000 + (k * nWidth + i));
            btn[k * nWidth + i] -> SetFont(font);
            grid -> Add(btn[k * nWidth + i], 1, wxEXPAND | wxALL);
            btn[k * nWidth + i] -> Bind(wxEVT_COMMAND_BUTTON_CLICKED, &myMain::OnButtonClicked, this);

            nField[k * nWidth + i] = 0;
        }
        
    }
    this->SetSizer(grid);
    grid-> Layout();
    
}

myMain::~myMain()
{
}

void myMain::OnButtonClicked(wxCommandEvent &evt){
    int x = ((evt.GetId() - 10000) % nWidth);
    int y = ((evt.GetId() - 10000) / nWidth);

    if(bFirstClick){
        int mines = 30;
        while(mines){
            int rx = rand() % nWidth;
            int ry = rand() % nHeight;

            if(nField[ry * nWidth + rx] == 0 && rx != x && ry != y){
                nField[ry * nWidth + rx] = -1;
                mines--;
            }
        }
        bFirstClick = false;
    }

    //Disable button
    btn[y * nWidth + x] -> Enable(false);

    //Check for collision
    if(nField[y * nWidth + x] == -1){
        wxMessageBox("BOOM!!!! - Game Over");

        bFirstClick = true;

        for(int x = 0; x < nWidth; x++){
            for(int y = 0; y < nHeight; y++){
                nField[y * nWidth + x] = 0;
                btn[y * nWidth + x] -> SetLabel("");
                btn[y * nWidth + x] -> Enable(true);
            }
        }


    }else{

        int mineCount = 0;
        for (int i = -1; i < 2; i++)
        {
            for(int k = -1; k < 2; k++){
                if(x + i >= 0 && x+i < nWidth && y + k >= 0 && y + k < nHeight){
                    if(nField[(y+k)*nWidth + (x+i)] == -1){
                        mineCount++;
                    }
                }
            }
        }

        if (mineCount > 0)
        {
            btn[y * nWidth + x]->SetLabel(std::to_string(mineCount));
        }
    }
    evt.Skip();
}