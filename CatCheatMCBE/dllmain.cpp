#include "Includes.hpp"

void mainThread(LPVOID lpParam) {
    FileSys::Initialize("CatCheat");
    FileSys::WriteLogOutput("Injected Cheat.");

    Hooks::InitHooks();

    while (!KeyMap[VK_DELETE] && KeyMap.contains(VK_DELETE))
        Sleep(1);

    FreeLibraryAndExitThread(static_cast<HMODULE>(lpParam), EXIT_SUCCESS);
}

void cleanThread() { /* Called After FreeLibraryAndExitThread */

    Hooks::UninitHooks();

    FileSys::WriteLogOutput("Uninjected.");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwCallReason, LPVOID lpReserved) {
    switch (dwCallReason) {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(mainThread), hModule, NULL, nullptr);
        break;
    case DLL_PROCESS_DETACH:
        cleanThread();
        break;
    }

    return TRUE;
}

