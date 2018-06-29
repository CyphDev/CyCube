#include <iostream>
#include <Windows.h>
#include "Header.h"
#include "resource.h"
#include <stdlib.h>
#include <winres.h>

using namespace std;

int main()
{
	system("CLS");
	cout << "\n      Welcome to CyCube v0.2!\n";

	HWND hWnd = GetConsoleWindow();
	RECT rcScr, rcWnd, rcClient;
	GetWindowRect(hWnd, &rcWnd);
	GetWindowRect(GetDesktopWindow(), &rcScr);
	GetClientRect(hWnd, &rcClient);

	MoveWindow(hWnd, (rcScr.right / 2) - 330, (rcScr.bottom / 2) - 180, rcWnd.right - rcWnd.left, rcWnd.bottom - rcWnd.top, 1);
	SetWindowLong(hWnd, GWL_STYLE, WS_POPUP);
	SetWindowRgn(hWnd, CreateRectRgn(rcClient.left + 2, rcClient.top + 2, rcClient.right + 2, rcClient.bottom + 2), TRUE);
	ShowWindow(hWnd, 1);

	HWND consoleWindow = GetConsoleWindow(); // Position
	SetWindowPos(consoleWindow, 0, 1645, 750, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	windowChecker:

	system("CLS");
	HWND hwnd = FindWindowA(0, ("AssaultCube"));

	if (hwnd)
	{
		GetWindowThreadProcessId(hwnd, &processID);
		HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);

		HWND console = GetConsoleWindow();
		RECT ConsoleRect;
		GetWindowRect(console, &ConsoleRect);
		MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 296, 230, TRUE); // Measurements

		system("color 0A");
		cout << "\n\n\n             CONTROLS\n";
		cout << "\n    F1: Toggle Infinite Ammo\n";
		cout << "    F2: Toggle Rapid Fire\n";
		cout << "    F3: Toggle Infinite Grenades\n";
		cout << "    F4: Toggle Infinite Health\n";
		cout << "    F5: Toggle Infinite Armor\n";
		cout << "    F6: Toggle Fly Hack\n";

		while (hwnd)
		{
			if (GetAsyncKeyState(VK_F1) & 1)
			{
				f1bool = !f1bool;
			}

			if (f1bool)
			{
				// Assault Rifle Ammo
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x150), &twentyvalue, sizeof(twentyvalue), 0);

				// Pistol Ammo
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x13C), &tenvalue, sizeof(tenvalue), 0);

				// SMG Ammo
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x148), &thirtyvalue, sizeof(thirtyvalue), 0);

				// Carbine Ammo
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x140), &tenvalue, sizeof(tenvalue), 0);

				// Sniper Ammo
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x14C), &fivevalue, sizeof(fivevalue), 0);

				// Shotgun Ammo
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x144), &sevenvalue, sizeof(sevenvalue), 0);
			}

			if (GetAsyncKeyState(VK_F2) & 1)
			{
				f2bool = !f2bool;
			}

			if (f2bool)
			{
				// Pistol Timer
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x164), &zerovalue, sizeof(zerovalue), 0);

				// SMG Timer
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x170), &zerovalue, sizeof(zerovalue), 0);

				// Grenade Timer
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x180), &zerovalue, sizeof(zerovalue), 0);

				// Assault Rifle Timer
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x178), &zerovalue, sizeof(zerovalue), 0);

				// Carbine Timer
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x168), &zerovalue, sizeof(zerovalue), 0);

				// Sniper Timer
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x174), &zerovalue, sizeof(zerovalue), 0);

				// Shotgun Timer
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x16C), &zerovalue, sizeof(zerovalue), 0);

				// Knife Timer
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x160), &zerovalue, sizeof(zerovalue), 0);
			}

			if (GetAsyncKeyState(VK_F3) & 1)
			{
				f3bool = !f3bool;
			}

			if (f3bool)
			{
				// Grenades
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x158), &highvalue, sizeof(highvalue), 0);
			}
			else
			{
				// Grenades
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0x158), &zerovalue, sizeof(zerovalue), 0);
			}

			if (GetAsyncKeyState(VK_F4) & 1)
			{
				f4bool = !f4bool;
			}

			if (f4bool)
			{
				// Health
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0xF8), &onehundredvalue, sizeof(onehundredvalue), 0);
			}

			if (GetAsyncKeyState(VK_F5) & 1)
			{
				f5bool = !f5bool;
			}

			if (f5bool)
			{
				// Armor
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0xFC), &onehundredvalue, sizeof(onehundredvalue), 0);				
			}
			else
			{
				// Armor
				ReadProcessMemory(pHandle, (LPVOID)(0x509B74), &offset, sizeof(offset), 0);
				WriteProcessMemory(pHandle, (LPVOID)(offset + 0xFC), &zerovalue, sizeof(zerovalue), 0);
			}

			if (GetAsyncKeyState(VK_F6) & 1)
			{
				f6bool = !f6bool;
			}

			if (f6bool)
			{
				if (GetAsyncKeyState(VK_SPACE))
				{
					// Player Z Coordinate
					ReadProcessMemory(pHandle, (LPVOID)(offset + 0xC), &playerZ, sizeof(playerZ), 0);
					playerZ += 0.0025;
					WriteProcessMemory(pHandle, (LPVOID)(offset + 0xC), &playerZ, sizeof(playerZ), 0);
				} 
				else
				{
					WriteProcessMemory(pHandle, (LPVOID)(offset + 0xC), &playerZ, sizeof(playerZ), 0);
				}

				if (GetAsyncKeyState(VK_LCONTROL))
				{
					// Player Z Coordinate
					ReadProcessMemory(pHandle, (LPVOID)(offset + 0xC), &playerZ, sizeof(playerZ), 0);
					playerZ -= 0.0025;
					WriteProcessMemory(pHandle, (LPVOID)(offset + 0xC), &playerZ, sizeof(playerZ), 0);
				}
				else
				{
					WriteProcessMemory(pHandle, (LPVOID)(offset + 0xC), &playerZ, sizeof(playerZ), 0);
				}
			}
		}
	}
	else
	{
		HWND console = GetConsoleWindow();
		RECT ConsoleRect;
		GetWindowRect(console, &ConsoleRect);
		MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 296, 100, TRUE); // Measurements
		
		system("CLS");
		system("color 4");
	 
		cout << "\n\n  AssaultCube could not be found,   please launch AssaultCube.\n\n";
	
		Sleep(750);

		goto windowChecker;
	}
}