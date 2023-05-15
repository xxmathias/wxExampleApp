#include "mainframe.hpp"

#include <curl/curl.h>
#include <curl/easy.h>
#include <wx/wx.h>
#include <codecvt>
#include <locale>

#include <wx/string.h>

#include <wx/spinctrl.h>


MainFrame::MainFrame(const wxString &title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize,
              wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER) {
  
  panel = new wxPanel(this);
  button = new wxButton(panel, wxID_ANY, "4AKIFT", wxPoint(150, 50), wxSize(100, 35));
  checkBox = new wxCheckBox(panel, wxID_ANY, "Check", wxPoint(350,30), wxSize(100,70));
  
  label = new wxStaticText(panel, wxID_ANY, "ABCD", wxPoint(150,100), wxSize(100,35));
  text = new wxTextCtrl(panel, wxID_ANY, "text", wxPoint(150, 150), wxSize(200,35));

  slider = new wxSlider(panel, wxID_ANY, 25,0,100, wxPoint(350,150), wxSize(200,-1));

  gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(150,200),wxSize(200,-1));

  gauge->SetValue(75);
  
  choices = new wxArrayString();
  choices->Add("Fabian");
  choices->Add("Alvin");
  choices->Add("Mihael");
  choices->Add("Neil");
  
  choice = new wxChoice(panel, wxID_ANY,wxPoint(150,260),wxSize(100,-1), *choices);
  choice->Select(0);

  spin = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(400,200));

  list = new wxListBox(panel, wxID_ANY, wxPoint(150,350), wxSize(100,-1), *choices);

  radioBox = new wxRadioBox(panel, wxID_ANY, "radioBox", wxPoint(285,300), wxDefaultSize, *choices);
}

