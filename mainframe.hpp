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
  
  wxTextCtrl* textInput1;
  wxTextCtrl* textInput2;
  
  wxButton* clearButton;
  wxButton* saveButton;
  wxButton* loadButton;
  
  void OnTextInput1KeyDown(wxKeyEvent& key);
  void OnTextInput2KeyDown(wxKeyEvent& key);
  
  void OnClearButton(wxCommandEvent &event);
  void OnSaveButton(wxCommandEvent &event);
  void OnLoadButton(wxCommandEvent &event);
  int WriteInFile(std::string str, bool append);

};

#endif // MAINFRAME_HPP
