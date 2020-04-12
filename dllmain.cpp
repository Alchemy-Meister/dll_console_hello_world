// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>

DWORD WINAPI MainThread(HMODULE hModule)
{
	AllocConsole();
	FILE* file;
	freopen_s(&file, "CONOUT$", "w", stdout);
	std::cout << "DLL Console Hello World!" << std::endl;

	while (true)
	{
		if (GetAsyncKeyState(VK_END) & 1)
		{
			break;
		}
	}

	if (file != NULL)
	{
		fclose(file);
	}

	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MainThread, hModule, NULL, NULL);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

