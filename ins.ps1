function Test-Admin {
    $identity = [System.Security.Principal.WindowsIdentity]::GetCurrent()
    $principal = New-Object System.Security.Principal.WindowsPrincipal($identity)
    return $principal.IsInRole([System.Security.Principal.WindowsBuiltInRole]::Administrator)
}

if (-Not (Test-Admin)) {
    Write-Host "This script must be run as an Administrator." -ForegroundColor Red
    Write-Host "Please right-click on PowerShell and select 'Run as Administrator'." -ForegroundColor Yellow
    exit
}

$folderPath = [System.IO.Path]::Combine([System.Environment]::GetFolderPath('LocalApplicationData'), 'wpac')
$zipUrl = 'https://github.com/Gur0v/wpac/releases/download/v0.1/wpac.zip'
$zipPath = Join-Path -Path $folderPath -ChildPath 'wpac.zip'

function Install-Wpac {
    if (-Not (Test-Path -Path $folderPath)) {
        New-Item -ItemType Directory -Path $folderPath
    }

    Invoke-WebRequest -Uri $zipUrl -OutFile $zipPath
    Expand-Archive -Path $zipPath -DestinationPath $folderPath
    Remove-Item -Path $zipPath

    $existingPath = [System.Environment]::GetEnvironmentVariable('Path', [System.EnvironmentVariableTarget]::Machine)
    if (-Not ($existingPath -like "*$folderPath*")) {
        $newPath = $existingPath + ";$folderPath"
        [System.Environment]::SetEnvironmentVariable('Path', $newPath, [System.EnvironmentVariableTarget]::Machine)
        Write-Host "Added $folderPath to the system PATH."
    } else {
        Write-Host "$folderPath is already in the system PATH."
    }

    Write-Host "Installation completed successfully."
}

Install-Wpac
