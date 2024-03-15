#include <Windows.h>
#include <iostream>
#include <string>

// Function to check if a specific Windows SDK is available
bool IsWindowsSDKPresent(const wchar_t* version)
{
    HKEY hKey;
    std::wstring keyPath = L"SOFTWARE\\Microsoft\\Microsoft SDKs\\Windows\\" + std::wstring(version);
    bool isPresent = false;

    // Open the registry key
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyPath.c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS)
    {
        isPresent = true;
        RegCloseKey(hKey);
    }

    return isPresent;
}

// Function to run FireCoreRuntime.exe in the background
void RunFireCoreRuntime()
{
    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;

    if (CreateProcess(L"C:\\Path\\To\\FireCoreRuntime.exe", nullptr, nullptr, nullptr, FALSE, CREATE_NO_WINDOW, nullptr, nullptr, &si, &pi))
    {
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
        std::wcout << L"FireCoreRuntime.exe is running in the background." << std::endl;
    }
    else
    {
        std::wcerr << L"Failed to start FireCoreRuntime.exe." << std::endl;
    }
}

// Function to handle Windows SDK presence and execute appropriate code
void HandleWindowsSDKPresence()
{
    // Check if Windows 10 SDK is present
    if (IsWindowsSDKPresent(L"v10.0"))
    {
        // Windows 10 SDK is available, reference it here
        // Add your code here to use the Windows 10 SDK
    }
    else if (IsWindowsSDKPresent(L"v8.0"))
    {
        // Windows 8 SDK is available, reference it here
        // Add your code here to use the Windows 8 SDK
    }
    else
    {
        // Neither Windows 10 nor Windows 8 SDK is available
        // Add your fallback code here for unsupported systems
    }
}

int main()
{
    // Handle Windows SDK presence and execute appropriate code
    HandleWindowsSDKPresence();

    // Run FireCoreRuntime.exe when the UWP app is being run
    // You can trigger this function based on specific conditions when the UWP app is running.
    RunFireCoreRuntime();

    return 0;
}