#include "Includes.hpp"

void mainThread(LPVOID lpParam) {
    FileSys::Initialize("CatCheat");
    FileSys::WriteLogOutput("Injected Cheat.");

    FreeLibraryAndExitThread(static_cast<HMODULE>(lpParam), EXIT_SUCCESS);
}

void cleanThread() { /* Called After FreeLibraryAndExitThread */
    FileSys::WriteLogOutput("Free'd Library.");
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

