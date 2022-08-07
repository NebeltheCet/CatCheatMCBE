#include "../../../../Includes.hpp"

typedef void(__fastcall* Mouse)(uint64_t, char, bool);
inline Mouse oMouse;

void hkMouse(uint64_t unk1, char mouseAction, bool IsDown) {
	if (mouseAction == (1 || 2)) { /* Add LMB and RMB to the KeyMap */
		KeyMap[mouseAction] = IsDown;
	}

	oMouse(unk1, mouseAction, IsDown);
}

void Mousehk::InitHook() {
	uint64_t Mouse_Sig = Memory::FindSignature("48 83 EC ? 0F B6 C1 4C 8D 05");
	if (Mouse_Sig <= NULL) { /* Invalid Signature */
		FileSys::WriteLogOutput("[Mouse] Invalid Signature.");
		return;
	}

	if (MH_CreateHook((void*)Mouse_Sig, &hkMouse, reinterpret_cast<LPVOID*>(&oMouse)) != MH_STATUS::MH_OK) {
		FileSys::WriteLogOutput("[Mouse] Failed to Create Hook.");
		return;
	}

	if (MH_EnableHook((void*)Mouse_Sig) != MH_STATUS::MH_OK) {
		FileSys::WriteLogOutput("[Mouse] Failed to Enable Hook.");
		return;
	}
}