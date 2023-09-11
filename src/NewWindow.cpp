// NewWindow.cpp
#include "../include/NewWindow.hpp"

NewWindow::NewWindow(const wxString &title, const wxString &textInput)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200)) {
    textCtrl = new wxTextCtrl(this, wxID_ANY, textInput, wxDefaultPosition, wxSize(200, 35));
}
