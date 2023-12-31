#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

extern "C"
{
	DWORD DACOM_GetDllVersion(LPCSTR moduleFileName, PDWORD major, PDWORD minor, PDWORD build);
}