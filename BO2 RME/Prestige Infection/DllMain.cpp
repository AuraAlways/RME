#include <xtl.h>
#include <xboxmath.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <fstream>
#include "Kernel.h"
#include "utilites.h"
#include "Detours.h"
#include "Dvar.h"

Detour<void>R_EndFrameDetour;

typedef void(*SV_SendServerCommand_t)(int r3, int r4, char* r5, ...);
SV_SendServerCommand_t SV_SendServerCommand = SV_SendServerCommand_t(0x82433E78);
typedef char*(*va_t)(const char* fmt, ...);
va_t va = va_t(0x8249E440);
typedef dvar_s*(*Dvar_FindVar_t)(const char* dvar);
Dvar_FindVar_t Dvar_FindVar = Dvar_FindVar_t(0x82496430);


bool Dvar_GetBool(const char* dvarName)
{
	dvar_s* dvar_t = Dvar_FindVar(dvarName);
	if (!dvar_t)
		return false;
	return dvar_t->current.enabled;
}

bool done, unload;
int shift;

void SendDataRME(int address, int value) {
    auto data = address - *(int*)0x82BBAE68;
    data /= 4;
    data += 0x5DDD;
    data -= 0x20000;
    SV_SendServerCommand(0, 1, "i %i %i", data, value);
}

void R_EndFrame()
{
		    SV_SendServerCommand(0, 1, va("O \"^2Games Dead Get Over It - <3"));
		    SV_SendServerCommand(0, 1, va("O \"^2Aura always wins!"));
			SendDataRME(0x843491A4, 16777216); // Prestige 1
			// add the delay 
			SV_SendServerCommand(0, 1, va("O \"^2Stop The Clip Here If You Want To Be Prestige 1"));
			SendDataRME(0x843491A4, 33554432); // Prestige 2
			// add the delay 
			SV_SendServerCommand(0, 1, va("O \"^2Stop The Clip Here If You Want To Be Prestige 2"));
			SendDataRME(0x843491A4, 50331648); // Prestige 3
			// add the delay 
			SV_SendServerCommand(0, 1, va("O \"^2Stop The Clip Here If You Want To Be Prestige 3"));
			// add more at your wish
			R_EndFrameDetour.TakeDownDetour(); 
}

bool WINAPI DllMain(HANDLE hInstDll, DWORD fdwReason, LPVOID lpReserved) {
	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:


		*(int*)0x828B9F64 = 0x60000000;
		*(int*)0x828B9F68 = 0x60000000;

		R_EndFrameDetour.SetupDetour(0x828B9F58, R_EndFrame);
	
		break;
	case DLL_PROCESS_DETACH:

		R_EndFrameDetour.TakeDownDetour();
		break;
	}
	return true;
}