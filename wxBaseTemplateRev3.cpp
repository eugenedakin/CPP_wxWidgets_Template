// C++ TF-Luna Program
#include <wx/wx.h>
#include <wx/statbox.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <gpiod.h>
#include <linux/i2c-dev.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>

class MywxBaseApp : public wxApp
{
public:
    bool OnInit() override;
};
 
wxIMPLEMENT_APP(MywxBaseApp);

class MyForm : public wxFrame
{
public:
    MyForm(); //Add constructor declaration
    ~MyForm(); // Add destructor declaration
 
private:
	void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnMenuNew(wxCommandEvent& event);
    void OnSampleButton(wxCommandEvent& event);
    wxStaticText *label1;
};
  
  enum
{
    ID_MenuNew = 1,
    ID_SampleButton,
    ID_GBGetInfo
};  

bool MywxBaseApp::OnInit()
{
    MyForm *form = new MyForm();
    form->Show(true);
    return true;
}

void MyForm::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets C++ example program",
                 "About Template", wxOK | wxICON_INFORMATION);
}

void MyForm::OnExit(wxCommandEvent& event)
{
    // Destructor will be called automatically when window closes
    Close(true);
}

void MyForm::OnMenuNew(wxCommandEvent& event)
{
    wxLogMessage("Something New!");
}

// Add destructor implementation
MyForm::~MyForm()
{
    // Place destructor code here
}
MyForm::MyForm()
    : wxFrame(nullptr, wxID_ANY, "wx Template", wxDefaultPosition, wxSize(776, 650))
  
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_MenuNew, "&New\tCtrl-N",
                     "Start something new, etc.");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
 
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
 
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
 
    SetMenuBar(menuBar);
     
    CreateStatusBar();
    SetStatusText("Example status text");
    ///////////////////////
    // Create main panel //
    ///////////////////////
    wxPanel *panel = new wxPanel(this, wxID_ANY);
    
    ///////////////////
    //Create a label //
    ///////////////////
    label1 = new wxStaticText(panel, wxID_ANY, "wxWidgets Template", wxPoint(100, 0), wxSize(560, 20), wxALIGN_CENTER_HORIZONTAL);
    
    //Bind Events
    Bind(wxEVT_MENU, &MyForm::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyForm::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MyForm::OnMenuNew, this, ID_MenuNew);
    Bind(wxEVT_BUTTON, &MyForm::OnSampleButton, this, ID_SampleButton);
    
    /////////////////////////////////////////////////////////
    // Create StaticBox (GroupBox) in the center - Get Info //
    /////////////////////////////////////////////////////////
    wxStaticBox *GBGetInfo = new wxStaticBox(panel, ID_GBGetInfo, "Get Info", wxPoint(100, 60), wxSize(560,50));
    
    // Create button inside the group box. Use Raise() to ensure the button appears above the static box in the z-order
    wxButton *sampleButton = new wxButton(panel, ID_SampleButton, "Sample", wxPoint(320, 77), wxSize(120, 26));
    sampleButton->Raise();
	}
void MyForm::OnSampleButton(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets C++ sample button",
                 "sample button", wxOK | wxICON_INFORMATION);
}
