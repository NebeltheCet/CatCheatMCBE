#include "../../../Includes.hpp"

bool InputSys::IsKeyDown(uint64_t key) {
	return (KeyMap.contains(key) ? KeyMap[key] : false);
}

bool InputSys::IsKeyReleased(uint64_t key) {
	if (!KeyMap.contains(key))
		return false;

	bool keyMap = KeyMap[key];
	static bool previousKeyMap = false;
	bool fuckingReturn = false;
	if (previousKeyMap && !keyMap) {
		fuckingReturn = true;
	}

	previousKeyMap = keyMap;
	return fuckingReturn;
}

bool InputSys::IsKeyToggled(uint64_t key) {
	if (!KeyMap.contains(key))
		return false;

	bool keyMap = KeyMap[key];
	static bool previousKeyMap = false;
	static bool fuckingReturn = false;
	if (previousKeyMap && !keyMap) {
		fuckingReturn = !fuckingReturn;
	}

	previousKeyMap = keyMap;
	return fuckingReturn;
}