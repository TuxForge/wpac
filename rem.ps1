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

function Remove-Wpac {
    $existingPath = [System.Environment]::GetEnvironmentVariable('Path', [System.EnvironmentVariableTarget]::Machine)

    if ($existingPath -like "*$folderPath*") {
        $pathArray = $existingPath -split ';'
        $newPathArray = $pathArray | Where-Object { $_ -ne $folderPath }
        $newPath = [string]::Join(';', $newPathArray)
        [System.Environment]::SetEnvironmentVariable('Path', $newPath, [System.EnvironmentVariableTarget]::Machine)
        Write-Host "Removed $folderPath from the system PATH."

        if (Test-Path -Path $folderPath) {
            Remove-Item -Path $folderPath -Recurse -Force
            Write-Host "Deleted the folder: $folderPath."
        } else {
            Write-Host "The folder $folderPath does not exist."
        }
    } else {
        Write-Host "$folderPath is not in the system PATH."
    }
}

Remove-Wpac
