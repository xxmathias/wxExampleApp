#include "mainframe.hpp"
#include <wx/wx.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream> 
#include <filesystem>
#include <wx/string.h>
#include <wx/spinctrl.h>

int MainFrame::WriteInFile(std::string str, bool append) {
  std::ofstream myfile;
  if(append) {
    myfile.open("data.txt", std::ofstream::out | std::ofstream::app);
  } else {
    myfile.open("data.txt", std::ofstream::out);
  }

  if(myfile.is_open()){
      myfile << str << std::endl;
      myfile.close();
  } else {
      std::cerr << "Unable to open file" << std::endl;
      return -1;
  }
  return 0;
}

void MainFrame::OnSaveButton(wxCommandEvent& event) {
  if(textInput1->GetValue().ToStdString() != "") {
    std::string text1 = textInput1->GetValue().ToStdString();
    std::string text2 = textInput2->GetValue().ToStdString();
    std::vector<std::string> text1v;
    std::vector<std::string> text2v;
    text1v.push_back(text1);
    text2v.push_back(text2);
    
    // erase data and write ascii
    for(auto& e : text1v) {WriteInFile(e, false);}
    
    // append hex
    for(auto& e : text2v) {WriteInFile(e, true);}
  }
}

void MainFrame::OnLoadButton(wxCommandEvent& event) {
  std::ifstream myfile;
  std::string str, ascii, hex;
  myfile.open("data.txt");
  if(myfile.is_open()){
    while(std::getline(myfile, str)) {
      if(ascii == "") {
        ascii = str;
      } else {
        hex = str; 
      }
    }
    myfile.close();

    // Assuming the ASCII string is on the first line and the hex string is on the second line
    textInput1->SetValue(ascii);
    textInput2->SetValue(hex);
  } else {
    std::cerr << "Unable to open file" << std::endl;
  }
}
  

void MainFrame::OnClearButton(wxCommandEvent& event) {
  textInput1->Clear();
  textInput2->Clear();
}

void MainFrame::OnTextInput1KeyDown(wxKeyEvent& key) {
  if (key.GetUnicodeKey() == 8) {
    wxString hexStr = textInput1->GetValue();
    if(!hexStr.IsEmpty()) {
      hexStr.RemoveLast();
      textInput1->SetValue(hexStr);
    }
  } else {
    std::string keyStr(1, static_cast<char>(key.GetUnicodeKey()));
    textInput1->AppendText(keyStr);
  }
}

void MainFrame::OnTextInput2KeyDown(wxKeyEvent& key) {
  if (key.GetUnicodeKey() == 8) {
    wxString hexStr = textInput2->GetValue();
    if(!hexStr.IsEmpty()) {
      hexStr.RemoveLast();
      textInput2->SetValue(hexStr);
    }
  } else {
    std::string keyStr(1, static_cast<char>(key.GetUnicodeKey()));
    textInput2->AppendText(keyStr);
  }
}


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
  
  textInput1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(0, 800), wxSize(100,100));
  textInput1->Bind(wxEVT_CHAR, &MainFrame::OnTextInput1KeyDown, this);
  textInput2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(500, 800), wxSize(100,100));
  textInput2->Bind(wxEVT_CHAR, &MainFrame::OnTextInput2KeyDown, this);
  clearButton = new wxButton(panel, wxID_ANY, "CLEAR", wxPoint(0, 1000), wxSize(200, 200));
  clearButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearButton, this);
  saveButton = new wxButton(panel, wxID_ANY, "SAVE", wxPoint(350, 1000), wxSize(200,200));
  saveButton->Bind(wxEVT_BUTTON, &MainFrame::OnSaveButton, this);
  loadButton = new wxButton(panel, wxID_ANY, "LOAD", wxPoint(700, 1000), wxSize(200,200));
  loadButton->Bind(wxEVT_BUTTON, &MainFrame::OnLoadButton, this);
}

