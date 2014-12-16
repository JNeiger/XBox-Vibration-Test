// XBox_VibrationTest.cpp : Defines the entry point for the console application.
//

#define WIN32_LEAN_AND_MEAN // We don't want the extra stuff like MFC and such

#include "stdafx.h"
#include <Windows.h>
#include <Xinput.h>
#pragma comment(lib, "XInput.lib")   // Library. If your compiler doesn't support this type of lib include change to the corresponding one

int valid = -1;

int _tmain(int argc, _TCHAR* argv[])
{
	DWORD dwResult;

	for (DWORD i = 0; i < XUSER_MAX_COUNT; i++)
	{
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		dwResult = XInputGetState(i, &state);

		if (dwResult == ERROR_SUCCESS) {
			printf("Found controller %i \n", i);
			valid = i;
		}else
			printf("Contorller not found\n");
	}

	XINPUT_VIBRATION vibration;

	for (unsigned int i = 0; i < 65535; i++) {
		ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
		vibration.wLeftMotorSpeed = i;
		vibration.wRightMotorSpeed = i;
		XInputSetState(valid, &vibration);
		if (i % 10 == 0)
			Sleep(1);
	}

	Sleep(1000);
	return 0;
}

