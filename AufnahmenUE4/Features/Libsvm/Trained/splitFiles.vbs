Dim ScriptPath
ScriptPath = Left(WScript.ScriptFullName, InStrRev(WScript.ScriptFullName, "\"))

Dim objFileSystem
Set objFileSystem = WScript.CreateObject("Scripting.FileSystemObject")

strFolderPath = objFileSystem.GetParentFolderName(objFileSystem.GetParentFolderName(ScriptPath))
objFolder = objFileSystem.GetFolder(strFolderPath)

Set objFileList = objFolder.Files
for each objFile in objFileList
    if InStr(objFile.Name,"10")>0 then
        objFileSystem.moveFile objFileSystem.GetAbsolutePathName(objFile) strFolderPath & "Features\Test\"
    elseif InStr(objFile.Name,"1")>0 then
        objFileSystem.moveFile objFileSystem.GetAbsolutePathName(objFile) strFolderPath & "Features\Training\"
    elseif InStr(objFile.Name,"2")>0 then
        objFileSystem.moveFile objFileSystem.GetAbsolutePathName(objFile) strFolderPath & "Features\Test\"
    elseif InStr(objFile.Name,"3")>0 then
        objFileSystem.moveFile objFileSystem.GetAbsolutePathName(objFile) strFolderPath & "Features\Training\"
    elseif InStr(objFile.Name,"4")>0 then
        objFileSystem.moveFile objFileSystem.GetAbsolutePathName(objFile) strFolderPath & "Features\Test\"
    elseif InStr(objFile.Name,"5")>0 then
        objFileSystem.moveFile objFileSystem.GetAbsolutePathName(objFile) strFolderPath & "Features\Training\"
    elseif InStr(objFile.Name,"6")>0 then
        objFileSystem.moveFile objFileSystem.GetAbsolutePathName(objFile) strFolderPath & "Features\Test\"
    elseif InStr(objFile.Name,"7")>0 then
        objFileSystem.moveFile objFileSystem.GetAbsolutePathName(objFile) strFolderPath & "Features\Training\"
    elseif InStr(objFile.Name,"8")>0 then
        objFileSystem.moveFile objFileSystem.GetAbsolutePathName(objFile) strFolderPath & "Features\Test\"
    elseif InStr(objFile.Name,"9")>0 then
        objFileSystem.moveFile objFileSystem.GetAbsolutePathName(objFile) strFolderPath & "Features\Training\"
next
MsgBox("Done")