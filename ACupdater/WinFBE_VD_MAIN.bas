#Define UNICODE
#Define _WIN32_WINNT &h0602
#Include Once "windows.bi"
#Include Once "Afx\CWindow.inc"
#define CODEGEN_FORM
#define CODEGEN_PROGRESSBAR
#define CODEGEN_LABEL
#Include once "WinFormsX\WinFormsX.bi"
Using Afx

' WINFBE_CODEGEN_START

Declare Function Core_Initialize( ByRef sender As wfxForm, ByRef e As EventArgs ) As LRESULT

type CoreType extends wfxForm
    private:
        temp as byte
    public:
        declare static function FormInitializeComponent( byval pForm as CoreType ptr ) as LRESULT
        declare constructor
        ' Controls
        Progress As wfxProgressBar
        Status As wfxLabel
end type


function CoreType.FormInitializeComponent( byval pForm as CoreType ptr ) as LRESULT
    dim as long nClientOffset

    pForm->Name = "Core"
    pForm->Text = "AC Updater"
    pForm->StartPosition = FormStartPosition.CenterScreen
    pForm->BorderStyle = FormBorderStyle.FixedToolWindow
    pForm->MinimizeBox = False
    pForm->MaximizeBox = False
    pForm->Icon = "IMAGE_ICON"
    pForm->SetBounds(10,10,300,125)
    pForm->OnInitialize = @Core_Initialize
    pForm->Progress.Parent = pForm
    pForm->Progress.Name = "Progress"
    pForm->Progress.SetBounds(22,25-nClientOffset,250,25)
    pForm->Status.Parent = pForm
    pForm->Status.Name = "Status"
    pForm->Status.Text = "Connecting..."
    pForm->Status.SetBounds(22,60-nClientOffset,250,21)
    pForm->Controls.Add(ControlType.ProgressBar, @(pForm->Progress))
    pForm->Controls.Add(ControlType.Label, @(pForm->Status))
    Application.Forms.Add(ControlType.Form, pForm)
    function = 0
end function

constructor CoreType
    InitializeComponent = cast( any ptr, @FormInitializeComponent )
    this.FormInitializeComponent( @this )
end constructor

dim shared Core as CoreType

' WINFBE_CODEGEN_END

' ========================================================================================
' WinFBE - FreeBASIC Editor (Windows 32/64 bit)
' Visual Designer auto generated project
' ========================================================================================

' Main application entry point.
' Place any additional global variables or #include files here.

' For your convenience, below are some of the most commonly used WinFBX library
' include files. Uncomment the files that you wish to use in the project or add
' additional ones. Refer to the WinFBX Framework Help documentation for information
' on how to use the various functions.

' #Include Once "Afx\AfxFile.inc"
' #Include Once "Afx\AfxStr.inc"
' #Include Once "Afx\AfxTime.inc"
' #Include Once "Afx\CIniFile.inc"
' #Include Once "Afx\CMoney.inc"
' #Include Once "Afx\CPrint.inc"
#Include Once "windows.bi"
#Include Once "win\wininet.bi"
#Include Once "tools.inc"
#Include Once "core.inc"

Application.Run(Core)

#include once "E:\Storage\Workspaces\FreeBasic\ACupdater\frmMain.inc"

