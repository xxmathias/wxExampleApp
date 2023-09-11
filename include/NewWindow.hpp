// NewWindow.hpp
#ifndef NEWWINDOW_HPP
#define NEWWINDOW_HPP

#include <wx/wx.h>

class NewWindow : public wxFrame {
public:
    NewWindow(const wxString &title, const wxString &textInput);

private:
    wxTextCtrl* textCtrl;
};

#endif //NEWWINDOW_HPP