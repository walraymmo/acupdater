DIM Shared CONFIG_FILE AS STRING
Dim SHared BUILDVER_FILE as string

Dim SHared PATCH_PATH as string
DIm shared WINRAR_PATH as string

DIM Shared BASE_URL as STRING
DIM shared PATCH_PREFIX as string
DIM shared PATCH_SUFIX as string
DIM shared PATCH_NUMBER as Integer

DIm shared TIMEOUT as integer

Declare Function FileExists(Byval path as string) AS Boolean
Declare Function DirExists(Byval path as string) AS Boolean

Sub procreate(byval exe as string)
    Dim ret as Integer
    Dim as PROCESS_INFORMATION pi
    Dim as STARTUPINFO si
        si.dwFlags=STARTF_USESHOWWINDOW  'this is required for:
        si.wShowWindow=SW_SHOWNOACTIVATE ' "or" these if multiple
        si.cb=Len(si)

    ret=CreateProcess(_
        Null,_ 'this param doesn't work consistently, use:
        exe,_ 'complete path and quote as needed
        Null,_
        Null,_
        False,_
        CREATE_NEW_CONSOLE,_ 'set priority here, #6..
        Null,_
        Exepath,_
        @si,_
        @pi)
End Sub

Sub SetConfig
    Open (CONFIG_FILE) For Output as #1
        Print #1, "url: " & BASE_URL
        Print #1, "prefix: " & PATCH_PREFIX
        Print #1, "sufix: " & PATCH_SUFIX
        Print #1, "winrar: " & WINRAR_PATH
    Close #1
End Sub

Sub GetConfig
    If FileExists(CONFIG_FILE) Then
        Open (CONFIG_FILE) For Input as #1
            For i as Integer = 1 To 4
                Select Case i
                    Case 1
                        Line Input #1, BASE_URL
                        BASE_URL = Trim(Right(BASE_URL,Len(BASE_URL) - 5))
                    Case 2
                        Line Input #1, PATCH_PREFIX
                        PATCH_PREFIX = Trim(Right(PATCH_PREFIX,Len(PATCH_PREFIX) - 8))
                    Case 3
                        Line Input #1, PATCH_SUFIX
                        PATCH_SUFIX = Trim(Right(PATCH_SUFIX,Len(PATCH_SUFIX) - 7))
                    Case 4
                        Line Input #1, WINRAR_PATH
                        WINRAR_PATH = Trim(Right(WINRAR_PATH,Len(WINRAR_PATH) - 8))
                        if Not FileExists(WINRAR_PATH) then 
                            MessageBox NULL, "WinRAR not found", Core.Text, MB_OK + MB_ICONERROR
                            Sleep TIMEOUT
                            End
                        end If
                End Select
            Next
        Close #1
    else
        'Globals
        BASE_URL = "https://raw.githubusercontent.com/walraymmo/acupdater/main/"
        PATCH_PREFIX = "patch_"
        PATCH_SUFIX = ""
        WINRAR_PATH = "C:\Program Files\WinRAR\winrar.exe"

        SetConfig
    END If
End Sub

Sub SetPatchNumber
    Open (BUILDVER_FILE) For Output as #1
        Print #1, Str(PATCH_NUMBER)
    Close #1
end sub

Sub GetPatchNumber
    DIm res as string
    If FileExists(BUILDVER_FILE) Then
        Open (BUILDVER_FILE) For Input as #1
            Line Input #1, res
            PATCH_NUMBER = Val(Trim(res))
        Close #1
    Else
        'Globals
        PATCH_NUMBER = 0

        SetPatchNumber
    End if
end sub

Function FileExists(Byval path as string) as Boolean
    If Dir(path) <> "" Then
        Return true
    end if
    Return false
end Function

Function DirExists(Byval path as string) as Boolean
    If Dir(PATCH_PATH & "\*.*") <> "" Then
        Return true
    end if
    Return False
End Function
