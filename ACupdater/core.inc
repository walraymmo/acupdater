'download files, Windows only
' requires IE 4.0 or better
' tested using fb v.16b,
'   and fb v.17b from CVS (11/2006)
'

'http://prdownloads.sourceforge.net/fbc/FB-v0.17b-jul-30-testing-win32.zip?download

Sub Downloader(param As Any Ptr)

    Dim as string PATCH_FILENAME = PATCH_PREFIX & PATCH_NUMBER & ".zip"

    dim as string sURL = BASE_URL & PATCH_FILENAME & PATCH_SUFIX
    dim as string LFileName = PATCH_PATH & PATCH_FILENAME

    Dim As HINTERNET hOpen,hFile
    Dim As Integer ctot,nret,res,percent
    Dim As String scUserAgent = "ACupdater"
    Dim As Byte Ptr myBuffer = Allocate(1024)

    Dim As Integer bufferSize
    Dim As String buffer

    'Create an internet connection
    hOpen=InternetOpen(scUserAgent,INTERNET_OPEN_TYPE_DIRECT,NULL,NULL,0)
    If hOpen=0 Then
        Core.Status.Text = "Could not connect to the internet" 'failed..
    end if

    'Set timeout in milliseconds
    'timeout=5000
    'res=InternetSetOption(_
    '    hOpen,_
    '    INTERNET_OPTION_RECEIVE_TIMEOUT,_
    '    @timeout,_
    '    SizeOf(timeout))

    'Open the url
    hFile = InternetOpenUrl(hOpen,sURL,NULL,0,INTERNET_FLAG_RELOAD,0)
    If hFile=0 Then
        Core.Status.Text = "Could not connect to server" 'failed..
    End if

    'Let's get HTTP response status code...
    bufferSize = 10000
    buffer = Space(bufferSize)

    res=HttpQueryInfoA(hFile,_
        HTTP_QUERY_STATUS_CODE,_
        Strptr(buffer),_
        @bufferSize,_
        NULL)

    bufferSize=val(Trim(buffer))

    'Let's get the file size...
    'I think this requires IE 4.0 engine, not 3.0
    If bufferSize <> 200 Then
        Core.Status.Text ="No updates avalible"
        procreate("AdventureCraft.exe")
        Sleep TIMEOUT
        ENd
    end if

    'MessageBox NULL, Str(buffer), "Example", MB_ICONASTERISK

    bufferSize=32
    buffer = space(bufferSize)
    res=HttpQueryInfoA(hFile,_
        HTTP_QUERY_CONTENT_LENGTH,_
        Strptr(buffer),_
        @bufferSize,_
        NULL)

    'MessageBox NULL, Str(buffer), "Example", MB_ICONASTERISK

    bufferSize=val(Trim(buffer))
    'if res=FALSE or tbsize<1 then return -3 'failed, but don't care...

    If bufferSize>0 Then
        Core.Status.Text ="Updating..."
    end if

    Open LFileName For Binary Access Write As #1
        nret=99 
        While nret>0
            res=InternetReadFile(hFile,myBuffer,1024,@nret)
            If nret>0 Then
                Put #1,,myBuffer[0],nret
                ctot+=nret

                percent = (ctot / bufferSize) * 100
                Core.Progress.Value = percent
                'MessageBox NULL, Str(Core.Progress.StepValue), "Example", MB_ICONASTERISK

            End If
        Wend
    Close #1

    InternetCloseHandle(hFile)
    InternetCloseHandle(hOpen)
    Deallocate myBuffer

    'Unpack patch file
    Exec(WINRAR_PATH, _
        "x -ibck -o+ " & Chr(34) & LFileName &_
        Chr(34) & " *.* " & Chr(34) & PATCH_PATH & Chr(34))

    Kill(LFileName)

    Core.Status.Text ="Update completed"
    SetPatchNumber

    Sleep TIMEOUT
    procreate(COMMAND(0))
    ENd

end sub