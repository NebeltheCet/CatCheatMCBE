#include "../../Includes.hpp"

void Hooks::InitHooks() {
	if (MH_Initialize() != MH_STATUS::MH_OK) {
		FileSys::WriteLogOutput("[Hooks] Failed to Initialize.");
		return;
	}

	new KeyItemhk();
	new Mousehk();
}

void Hooks::UninitHooks() {
	MH_DisableHook(MH_ALL_HOOKS);
	MH_Uninitialize();
}