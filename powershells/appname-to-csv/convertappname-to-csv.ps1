<#
This is a simple powershell to get a csv out of a sample inf 
#>
param(
    [Parameter(Mandatory=$True)]
    [String]$Root

)
if (-not (Test-Path $Root)){
    return -1 
}

$IniFiles = Get-ChildItem -Filter *.ini -Path $Root 
$InfFiles = Get-ChildItem -Filter *.inf -Path $Root 
$AllFiles = $IniFiles + $InfFiles
$ExeNames = $null 
$CsvRecords = New-Object -TypeName System.Collections.ArrayList 

foreach ($File in $AllFiles){
    $Record = New-Object -TypeName psobject 
    $ExeNames = get-content $File | select-string -Pattern "Exename"
    $TitleLine = Get-Content -Path $File | select-string -Pattern "Title"

    foreach($ExeName in $ExeNames)
    {
        if ($ExeName -match "\.exe")
        {  
            $Executable = ($ExeName -split "=")[1]
            Add-Member -Name "Executable" -Value $Executable -InputObject $Record -MemberType NoteProperty
        }elseif ($ExeName -match "\.msi")
        {
            $MsiName = ($ExeName -split "=")[1]
            Add-Member -Name "Msi" -Value $MsiName -InputObject $Record -MemberType NoteProperty 
        }
    }
    
    $Title = ($TitleLine -split "=")[1] 
    Add-Member -Name "Title" -Value $Title -MemberType NoteProperty -InputObject $Record 
    $CsvRecords.Add($Record)
}

$RecCounter = 0 
foreach ($CsvRecord in $CsvRecords){
    if ($RecCounter -lt 1){
        $CsvRecord | ConvertTo-Csv -NoTypeInformation
    }else{
        $CsvRecord | ConvertTo-Csv -NoTypeInformation | Select-Object -Skip 1 
    }
    $RecCounter = $RecCounter +1
}

