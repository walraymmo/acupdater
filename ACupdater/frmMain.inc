' WINFBE FORM
' WINFBE VERSION 2.1.8
' LOCKCONTROLS=False
' SNAPLINES=True
' WINFBE FORM_START
' WINFBE IMAGES_START
'   IMAGE_START
'     IMAGENAME=IMAGE_ICON
'     FILENAME=.\icon.ico
'     RESOURCETYPE=RCDATA
'   IMAGE_END
' WINFBE IMAGES_END
' WINFBE CONTROL_START Form
'   PROPERTIES_START
'     PROP_NAME=Name
'     PROP_VALUE=Core
'     PROP_NAME=Left
'     PROP_VALUE=10
'     PROP_NAME=Top
'     PROP_VALUE=10
'     PROP_NAME=Width
'     PROP_VALUE=300
'     PROP_NAME=Height
'     PROP_VALUE=125
'     PROP_NAME=ChildForm
'     PROP_VALUE=False
'     PROP_NAME=Text
'     PROP_VALUE=AC Updater
'     PROP_NAME=WindowState
'     PROP_VALUE=FormWindowState.Normal
'     PROP_NAME=StartPosition
'     PROP_VALUE=FormStartPosition.CenterScreen
'     PROP_NAME=BorderStyle
'     PROP_VALUE=FormBorderStyle.FixedToolWindow
'     PROP_NAME=MinimizeBox
'     PROP_VALUE=False
'     PROP_NAME=MaximizeBox
'     PROP_VALUE=False
'     PROP_NAME=ControlBox
'     PROP_VALUE=True
'     PROP_NAME=Enabled
'     PROP_VALUE=True
'     PROP_NAME=Visible
'     PROP_VALUE=True
'     PROP_NAME=BackColor
'     PROP_VALUE=SYSTEM|Control
'     PROP_NAME=AcceptButton
'     PROP_VALUE=
'     PROP_NAME=AllowDrop
'     PROP_VALUE=False
'     PROP_NAME=KeyPreview
'     PROP_VALUE=False
'     PROP_NAME=CancelButton
'     PROP_VALUE=
'     PROP_NAME=Icon
'     PROP_VALUE=IMAGE_ICON
'     PROP_NAME=Locked
'     PROP_VALUE=False
'     PROP_NAME=MaximumHeight
'     PROP_VALUE=0
'     PROP_NAME=MaximumWidth
'     PROP_VALUE=0
'     PROP_NAME=MinimumHeight
'     PROP_VALUE=0
'     PROP_NAME=MinimumWidth
'     PROP_VALUE=0
'     PROP_NAME=Tag
'     PROP_VALUE=
'   PROPERTIES_END
'   EVENTS_START
'     EVENT_NAME=Initialize
'   EVENTS_END
' WINFBE CONTROL_END
' WINFBE CONTROL_START ProgressBar
'   PROPERTIES_START
'     PROP_NAME=Name
'     PROP_VALUE=Progress
'     PROP_NAME=Left
'     PROP_VALUE=22
'     PROP_NAME=Top
'     PROP_VALUE=25
'     PROP_NAME=Width
'     PROP_VALUE=250
'     PROP_NAME=Height
'     PROP_VALUE=25
'     PROP_NAME=AllowDrop
'     PROP_VALUE=False
'     PROP_NAME=Maximum
'     PROP_VALUE=100
'     PROP_NAME=Minimum
'     PROP_VALUE=0
'     PROP_NAME=StepValue
'     PROP_VALUE=1
'     PROP_NAME=Value
'     PROP_VALUE=0
'     PROP_NAME=Enabled
'     PROP_VALUE=True
'     PROP_NAME=Tag
'     PROP_VALUE=
'     PROP_NAME=ToolTip
'     PROP_VALUE=
'     PROP_NAME=ToolTipBalloon
'     PROP_VALUE=False
'     PROP_NAME=Locked
'     PROP_VALUE=False
'     PROP_NAME=Marquee
'     PROP_VALUE=False
'     PROP_NAME=MarqueeAnimationSpeed
'     PROP_VALUE=30
'     PROP_NAME=Vertical
'     PROP_VALUE=False
'     PROP_NAME=Visible
'     PROP_VALUE=True
'   PROPERTIES_END
'   EVENTS_START
'   EVENTS_END
' WINFBE CONTROL_END
' WINFBE CONTROL_START Label
'   PROPERTIES_START
'     PROP_NAME=Name
'     PROP_VALUE=Status
'     PROP_NAME=Left
'     PROP_VALUE=22
'     PROP_NAME=Top
'     PROP_VALUE=60
'     PROP_NAME=Width
'     PROP_VALUE=250
'     PROP_NAME=Height
'     PROP_VALUE=21
'     PROP_NAME=Text
'     PROP_VALUE=Connecting...
'     PROP_NAME=AllowDrop
'     PROP_VALUE=False
'     PROP_NAME=BackColor
'     PROP_VALUE=SYSTEM|Control
'     PROP_NAME=BackColorHot
'     PROP_VALUE=SYSTEM|Control
'     PROP_NAME=ForeColor
'     PROP_VALUE=SYSTEM|ControlText
'     PROP_NAME=ForeColorHot
'     PROP_VALUE=SYSTEM|ControlText
'     PROP_NAME=BorderStyle
'     PROP_VALUE=ControlBorderStyle.None
'     PROP_NAME=TextAlign
'     PROP_VALUE=LabelAlignment.TopLeft
'     PROP_NAME=Font
'     PROP_VALUE=Segoe UI,9,400,0,0,0,1
'     PROP_NAME=Enabled
'     PROP_VALUE=True
'     PROP_NAME=Tag
'     PROP_VALUE=
'     PROP_NAME=ToolTip
'     PROP_VALUE=
'     PROP_NAME=ToolTipBalloon
'     PROP_VALUE=False
'     PROP_NAME=Locked
'     PROP_VALUE=False
'     PROP_NAME=UseMnemonic
'     PROP_VALUE=True
'     PROP_NAME=Visible
'     PROP_VALUE=True
'   PROPERTIES_END
'   EVENTS_START
'   EVENTS_END
' WINFBE CONTROL_END
' WINFBE FORM_END
' WINFBE_CODEGEN_START
#if 0
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
#endif
' WINFBE_CODEGEN_END
' Core form code file

Function Core_Initialize( ByRef sender As wfxForm, ByRef e As EventArgs ) As LRESULT
    Function = 0

    'Locals
    Dim CONNECT As Any Ptr

    'Globals
    PATCH_PATH = Exepath & "\mapDownloads\"

    CONFIG_FILE = Exepath & "\acupdater.ini"
    BUILDVER_FILE = PATCH_PATH & "buildver.dat"

    TIMEOUT = 2000

    if Not DirExists(PATCH_PATH) or Not FileExists(Exepath & "\AdventureCraft.exe") then
        MessageBox NULL, "AdventureCraft.exe / mapDownloads folder not found", Core.Text, MB_OK + MB_ICONERROR
        Sleep TIMEOUT
        End
    end If

    'Calls
    GetConfig
    GetPatchNumber

    PATCH_NUMBER += 1

    'Threads
    CONNECT = ThreadCreate(@Downloader, 0)

End Function
