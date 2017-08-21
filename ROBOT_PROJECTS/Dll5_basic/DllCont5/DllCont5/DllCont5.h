//[Do NOT CHAGE]

#pragma once
#include <Windows.h>

#define DLL_CONT_VERSION (0x050)

//------------------------------------------------------------------------------------
typedef struct {
	// Function Pointer
	DWORD(*GetFunc)(const char *func_name);
}GOSIMU_DLL_FUNC;

