#pragma once
#include "myApp.h"

wxIMPLEMENT_APP(myApp);
myApp::myApp(){

}

myApp::~myApp(){

}

bool myApp::OnInit(){
    myFrame = new myMain();
    myFrame->Show();
    return true;
}