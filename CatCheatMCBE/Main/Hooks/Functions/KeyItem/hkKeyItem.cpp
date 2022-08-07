#include "../../../../Includes.hpp"

typedef void(__thiscall* AVKeyItem)(uint64_t, bool);
inline AVKeyItem oAVKeyItem;
void hkKeyItem(uint64_t PressedKey, bool IsDown) {
	KeyMap[PressedKey] = IsDown; /* Set all of the Keys to its State in the Game */

	oAVKeyItem(PressedKey, IsDown);
}

void KeyItemhk::InitHook() {
	uint64_t KeyItem_Sig = Memory::FindSignature("48 83 EC ? 0F B6 C1 4C 8D 05");
	if (KeyItem_Sig <= NULL) { /* Invalid Signature */
		FileSys::WriteLogOutput("[AVKeyItem] Invalid Signature.");
		return;
	}

	if (MH_CreateHook((void*)KeyItem_Sig, &hkKeyItem, reinterpret_cast<LPVOID*>(&oAVKeyItem)) != MH_STATUS::MH_OK) {
		FileSys::WriteLogOutput("[AVKeyItem] Failed to Create Hook.");
		return;
	}

	if (MH_EnableHook((void*)KeyItem_Sig) != MH_STATUS::MH_OK) {
		FileSys::WriteLogOutput("[AVKeyItem] Failed to Enable Hook.");
		return;
	}
}