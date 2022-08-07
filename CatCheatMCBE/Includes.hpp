#pragma once

/* Defines */
#define INRANGE(x,a,b)   (x >= a && x <= b)
#define GET_BITS( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define GET_BYTE( x )    (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))

#define WIN32_LEAN_AND_MEAN /* This removes all rarely used Windows.h Features to reduce size. */
#define _CRT_SECURE_NO_WARNINGS

/* Visual Studio Includes */
#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <Psapi.h>
#include <map>

/* External Includes */
/* Library Includes */
#include "SDK/Libraries/Minhook/MinHook.h"

/* Additions */
#include "SDK/Utilities/FileSystem/FileSystem.hpp"
#include "SDK/Utilities/InputSystem/InputSystem.hpp"
#include "SDK/Utilities/Memory/Memory.hpp"

/* Hook Related */
#include "Main/Hooks/Functions/KeyItem/hkKeyItem.hpp"
#include "Main/Hooks/Functions/Mouse/hkMouse.hpp"
#include "Main/Hooks/Hooks.hpp"