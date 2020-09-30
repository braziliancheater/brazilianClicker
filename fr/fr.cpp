// enjoy this one dear skidder | src by brazilian aka crimes | made in 2017 and is preatty shit thats why im releasing it 

#include <iostream>
#include <Windows.h>
#include <iostream>
#include <tlhelp32.h>
#include <conio.h>
#include <stdio.h>
#include <strsafe.h>

#include "xor.hpp"
#include "fr.hpp"
#include "clicking.hpp"

int main()
{
	// pretty basic antidump that just checks for a matching window tittles and closes the program, you can do much more tho
	AntiDump();

	// this makes the tittle of the program random each time!
	SetConsoleTitleA(random_string(10).c_str());

	for (int i = 0; i < 32; i++)
		delays[i] = 1000.0f / generate_random_float(10.0f, 15.0f);

	ShowConsoleCursor(false);

	void* hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	// makes sure that the user cant pause our console while selecting text
	SetConsoleMode(hConsoleOutput, ENABLE_EXTENDED_FLAGS);

	// simple check to make sure you have minecraft open when first opening the clicker
	while (!FindWindow((xor ("LWJGL")), nullptr))
	{
		printf(xor ("\n"));
		printf(xor ("\r  minecraft instance was not found :(\n"));
		printf(xor ("\r  exiting"));
		Sleep(3000);
		exit(-1);
	}
	// displays our logo! which we did on our header file
	logo();

	// makes the color of the console 15 see http://winapi.freetechsecrets.com/win32/WIN32SetConsoleTextAttribute.htm for a list of colors!
	SetConsoleTextAttribute(hConsoleOutput, 15);
	printf(xor ("\n\n"));
	theTime();
	printf(xor (" press a keybind for the autoclicker - "));
	// while keybind is 0 | which is on the start of the program | it defines to a key on our dictionary on or header
	while (keybind == 0) {
		for (int i = 3; i < 256; i++)
		{
			if (i == 13 | i == 89)
			{
				i += 1;
			}
			if (GetAsyncKeyState((i)&SHRT_MAX) && keybind == 0)
			{
				keybind = i;
				printf(xor ("done :)"));
				Sleep(1000);
			}
		}
	}

	// clears the terminal
	system("cls");

	// displaying our logo again! | this time for the main clicker window!
	logo();

	// prints some useful info for the user 
	SetConsoleTextAttribute(hConsoleOutput, 15);
	printf(xor ("\n\n"));
	theTime();
	printf(xor ("  your keycode - "));
	std::cout << keybind;
	printf(xor ("  selfdestruct - f10"));
	HWND windowHandle = FindWindowA(NULL, "LWJGL");
	if (windowHandle != 0) {
		std::cout << "  window not found";
	}
	else {
		std::cout << "  window found";
	}

	printf(xor ("\n\n"));

	// here we start the main methods/ac
	void* click = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)autoClicker, nullptr, 0, nullptr);
	CloseHandle(click);
	void* selfs = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)self, nullptr, 0, nullptr);
	CloseHandle(selfs);
	void* mineChecker = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)mineCheck, nullptr, 0, nullptr);
	CloseHandle(mineChecker);
	void* macaco = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)delay, nullptr, 0, nullptr);
	CloseHandle(macaco);
	// runs the final menu
	menu();
}

