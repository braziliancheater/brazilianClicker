#pragma once

#include <thread>

// this shit doesnt work but im sure you can fix it
// gl tho lol
void delay(void) {
	while (true) {
		if (GetKeyState(VK_UP) & 0x8000)
		{
			++cuzinho;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			--cuzinho;
		}
	}
}

void autoClicker(void) {
	// this looks for the window "LWJGL" which is minecraft and only clicks on it
	HWND hwnd = FindWindow("LWJGL", NULL);
	while (true) {
		// if toggled and mouse button down - click
		if (toggled && GetKeyState(VK_LBUTTON) & 0x8000) {
			SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, 0);
			SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, 0);
			std::this_thread::sleep_for(std::chrono::milliseconds(88));
			
		} // if not dont do shit
		else {
			Sleep(100);
		}
	}
}

