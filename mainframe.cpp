#include "mainframe.hpp"
#include <wx/wx.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream> 
#include <filesystem>
#include <wx/string.h>
#include <wx/spinctrl.h>
#include <wx/file.h>
#include "NewWindow.hpp"

void MainFrame::OnSaveAs(wxCommandEvent& event) {
    wxString defaultFileName = "test.md";
    wxString filePath = wxFileSelector("Save As", "", defaultFileName, ".md", "Markdown files (*.md)|*.md", wxFD_SAVE | wxFD_OVERWRITE_PROMPT, this);
    
    // Check if the user didn't cancel the dialog
    if (!filePath.IsEmpty()) {

        // Generate the markdown content
        wxString content;

        content += "## Weapons\n";
        content += "| Name | Strikes | Range | Type |\n";
        content += "| ---- | ------- | ----- | ---- |\n";



        // Write the markdown content to the file
        wxFile file(filePath, wxFile::write);
        if (file.IsOpened()) {
            file.Write(content);
            file.Close();
            wxLogMessage("File saved successfully!");
        } else {
            wxLogMessage("Failed to save the file.");
        }
    }
}


void MainFrame::WriteInFile(const std::string& str) {
    std::ofstream myfile;
    myfile.open("data.txt", std::ofstream::out | std::ofstream::app);

    if(myfile.is_open()) {
        myfile << str << std::endl;
        myfile.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
}

void MainFrame::OnSaveButton(wxCommandEvent& event) {
    std::string text1 = textInput1->GetValue().ToStdString();
    std::string text2 = textInput2->GetValue().ToStdString();
    

    // Clear the file first
    std::ofstream clearFile("data.txt", std::ofstream::out | std::ofstream::trunc);
    clearFile.close();
    
    WriteInFile(text1); 
    WriteInFile(text2);  
}
void MainFrame::OnLoadButton(wxCommandEvent& event) {
  // needs fix, only saves to 1st input field
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

void MainFrame::OnNewWindowButton(wxCommandEvent& event) {
    NewWindow *newWindow = new NewWindow("New Window", textInput1->GetValue());
    newWindow->Show(true);
}

enum
{
    ID_Hello = 1
};

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
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

  newWindowButton = new wxButton(panel, wxID_ANY, "New Window", wxPoint(700, 700), wxSize(200, 200));
  newWindowButton->Bind(wxEVT_BUTTON, &MainFrame::OnNewWindowButton, this);

    wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
  menuFile->Append(wxID_SAVE, "&Save As\tShift-Ctrl-S", "Help string shown in status bar for this menu item");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);

  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);

  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");

  SetMenuBar( menuBar );

  CreateStatusBar();
  SetStatusText("Welcome to wxWidgets!");

  menuBar->Bind(wxEVT_MENU, &MainFrame::OnHello, this, ID_Hello);
  menuBar->Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
  menuBar->Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
  menuBar->Bind(wxEVT_MENU, &MainFrame::OnSaveAs, this, wxID_SAVE);
}

