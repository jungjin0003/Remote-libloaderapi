# Remote-libloaderapi
This library is a remote version of Windows API libloaderapi.h

# Compilation method for each compilation
## MSVC
If you are using Visual Studio, you maybe just need to compile it. Because preprocessing library link was set up in the header

## mingw-gcc (Windows GCC)
```Shell
$ gcc main.c Rlibloaderapi.c -o main.exe -lntdll
```
gcc options `-lntdll` is link options for ntdll.lib library

# System Services Functions list in libloaderapi.h
* [AddDllDirectory](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-adddlldirectory)
* [DisableThreadLibraryCalls](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-disablethreadlibrarycalls)
* [FreeLibrary](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary)
* [FreeLibraryAndExitThread](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-freelibraryandexitthread)
* [GetModuleFileNameA](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamea)
* [GetModuleFileNameW](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew)
* [GetModuleHandleA](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlea)
* [GetModuleHandleExA](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandleexa)
* [GetModuleHandleExW](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandleexw)
* [GetModuleHandleW](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlew)
* [GetProcAddress](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress)
* [LoadLibraryA](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya)
* [LoadLibraryExA](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexa)
* [LoadLibraryExW](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw)
* [LoadLibraryW](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw)
* [RemoveDllDirectory](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-removedlldirectory)
* [SetDefaultDllDirectories](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-setdefaultdlldirectories)

## Remote version function implementation list in System Services Functions of libloaderapi.h
* GetModuleHandleA -> GetRemoteModuleHandleA
* GetModuleHandleW -> GetRemoteModuleHandleW
* GetModuleFileNameA -> GetRemoteModuleFileNameA
* GetModuleFileNameW -> GetRemoteModuleFileNameW
* GetProcAddress -> GetRemoteProcAddress

## Other new implementation functions
* RtlGetCurrentPeb -> GetRemotePeb
* GetModuleBaseNameA -> GetRemoteModuleBaseNameA
* GetModuleBaseNameW -> GetRemoteModuleBaseNameW