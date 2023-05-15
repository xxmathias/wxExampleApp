#include "app.hpp"
#include "mainframe.hpp"
#include <wx/wx.h>

bool App::OnInit() {
  MainFrame *main_frame = new MainFrame("Give me a name");
  main_frame->SetClientSize(1000, 1200);
  main_frame->Center();
  main_frame->Show();
  return true;
}

wxIMPLEMENT_APP(App);
