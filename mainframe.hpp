#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP
#include <wx/generic/grid.h>
#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
  MainFrame(const wxString &title);

private:
  wxPanel *panel;
  wxButton* button;
  wxCheckBox* checkBox;
  wxStaticText* label;
  wxTextCtrl* text;
  wxSlider* slider;
  wxGauge* gauge;
  wxArrayString* choices;
  wxChoice* choice;
  wxSpinCtrl* spin;
  wxListBox* list;
  wxRadioBox* radioBox;

};

#endif // MAINFRAME_HPP
