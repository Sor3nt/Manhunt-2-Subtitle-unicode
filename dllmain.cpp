
#include "MemoryMgr.h"

__int16 __cdecl WriteDebugDrawText(int outputString, const wchar_t* text)
{
	int stringLength = wcslen(text);

	int current = 0;

	do
	{
		*(int*)(outputString + 2 * current) = text[current];
		current++;
	} while (current < stringLength);

	*(int*)(outputString + 2 * current) = 0;

	return stringLength;
}

void __cdecl Print8(int translation, float a2, float a3, float a4, float a5, float a6, int a7)
{
	int local_208[258];
	const wchar_t* text = (const wchar_t*)translation;

	WriteDebugDrawText((int)local_208, text);
	((void(__cdecl*)(int, float, float, float, float, float, int, int))0x544180)((int)text, 0.05, a3, a4, a5, a6, a7, 0);
}

extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		Memory::VP::InjectHook(0x5443A0, Print8, PATCH_JUMP);

		Memory::VP::InjectHook(0x60EED1, 0x60EF02, PATCH_JUMP);
		Memory::VP::Patch<char>(0x60EF04, 0x01);
		Memory::VP::Patch<char>(0x60EF07, 0x01);
	}
}


