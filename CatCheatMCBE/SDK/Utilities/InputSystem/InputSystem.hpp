#pragma once

inline std::map<uint64_t, bool> KeyMap;
namespace InputSys {
	bool IsKeyDown(uint64_t);
	bool IsKeyReleased(uint64_t);
	bool IsKeyToggled(uint64_t);
}