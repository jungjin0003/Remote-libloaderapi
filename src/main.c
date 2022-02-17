#include <stdio.h>
#include "Rlibloaderapi.h"

int main(int argc, char *argv[])
{
    HANDLE hProcess;
    STARTUPINFOA si = { 0, };
    si.cb = sizeof(STARTUPINFOA);
    PROCESS_INFORMATION pi = { 0, };

    CreateProcessA("C:\\Windows\\System32\\notepad.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
    Sleep(10);
    HMODULE hModule = GetRemoteModuleHandleA(pi.hProcess, "user32.dll");
    char Filename[256];
    printf("%s : 0x%p\n", "user32.dll", hModule);
    GetRemoteModuleFileNameA(pi.hProcess, hModule, Filename, 256);
    printf("GetRemoteModuleFileNameA : %s\n", Filename);
    GetRemoteModuleBaseNameA(pi.hProcess, hModule, Filename, 256);
    printf("GetRemoteModuleBaseNameA : %s\n", Filename);
    printf("MessageBoxA : %p\n", GetRemoteProcAddress(pi.hProcess, hModule, "MessageBoxA"));
    TerminateProcess(pi.hProcess, 0);
#ifdef _WIN64
    ZeroMemory(&si, sizeof(STARTUPINFOA));
    ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
    CreateProcessA("C:\\Windows\\SysWOW64\\notepad.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
    Sleep(10);
    hModule = GetRemoteModuleHandleA(pi.hProcess, "user32.dll");
    printf("%s : 0x%p\n", "user32.dll", hModule);
    GetRemoteModuleFileNameA(pi.hProcess, hModule, Filename, 256);
    printf("GetRemoteModuleFileNameA : %s\n", Filename);
    GetRemoteModuleBaseNameA(pi.hProcess, hModule, Filename, 256);
    printf("GetRemoteModuleBaseNameA : %s\n", Filename);
    printf("MessageBoxA : %p\n", GetRemoteProcAddress(pi.hProcess, hModule, "MessageBoxA"));
    TerminateProcess(pi.hProcess, 0);
#endif

    system("pause");
}