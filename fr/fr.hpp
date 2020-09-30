#pragma once
#pragma warning(disable:4996)
#include <string>
#include <random>
#include <tchar.h>
#include <ctime>

// here we assign the main class variables 
// s/o eternityx1
std::string random_string(const int len) {
	const std::string alpha_numeric("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890");

	std::default_random_engine generator{ std::random_device{}() };
	const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };

	std::string str(len, 0);
	for (auto& it : str) {
		it = alpha_numeric[distribution(generator)];
	}

	return str;
}

// removes the console cursor 
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
// this just makes a random flot | that is going to be used as a timer beetween clicks
static auto generate_random_float = [](float min, float max) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = max - min;
	float r = random * diff;
	return min + r;
};

bool IsProcessRunning(const TCHAR* const executableName) {
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	const auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (!Process32First(snapshot, &entry)) {
		CloseHandle(snapshot);
		return false;
	}

	do {
		if (!_tcsicmp(entry.szExeFile, executableName)) {
			CloseHandle(snapshot);
			return true;
		}
	} while (Process32Next(snapshot, &entry));

	CloseHandle(snapshot);
	return false;
}

void AntiDump()
{
	if ((IsProcessRunning("notepad.exe") | IsProcessRunning("idaq64.exe") || IsProcessRunning("HxD.exe") ||
		IsProcessRunning("ResourceHacker.exe") || IsProcessRunning("ProcessHacker.exe") || IsProcessRunning("idaq32.exe")
		|| IsProcessRunning("httpdebugger.exe") || IsProcessRunning("windowrenamer.exe")))
	{
		exit(0);
	}

}
// our logo | you can change the it here
void logo(){
	void* hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput, 10);
	printf(xor ("   _                   _ _ _             \n"));
	printf(xor ("  | |__  _ __ __ _ ___(_) (_) __ _ _ __  \n"));
	printf(xor ("  | '_ \\| '__/ _` |_  / | | |/ _` | '_ \\ \n"));
	printf(xor ("  | |_) | | | (_| |/ /| | | | (_| | | | |\n"));
	printf(xor ("  |_.__/|_|  \\__,_/___|_|_|_|\\__,_|_| |_|clicker!\n"));
}

static int keybind = 0;
float delays[32]{ };
bool toggled = false;
float next_random_delay = 0.0f;
bool b_first_click;
bool b_mouse_down;
int cuzinho = 88;

void theTime() {
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "  [%I:%M:%S]", timeinfo);
	std::string str(buffer);

	std::cout << str;
	return;
}

void menu(void) {
	while (true) {
		void* hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

		WORD color;
		char enable;

		SetConsoleTextAttribute(hConsoleOutput, 15);
		printf(xor ("\r  active - "));
		color = 12;

		if (toggled)
			color = 10;

		SetConsoleTextAttribute(hConsoleOutput, color);
		SetConsoleCP(437);
		SetConsoleOutputCP(437);
		enable = 88;

		if (toggled)
			enable = 251;

		std::cout << enable;

		// prints the delay 
		// std::cout << cuzinho;

		Sleep(100);
	}
}
// skidded from empty! thanks latencyx <3
void self(void) {
	static bool pressed = false;
	
	while (!GetAsyncKeyState(VK_F10)) {
		if (GetKeyState(keybind) & 0x8000 && !pressed) {
			pressed = true;
		}
		else if (!(GetKeyState(keybind) & 0x8000) && pressed) {
			toggled = !toggled;
			pressed = false;
		}

		static auto last_tickcount = 0;
		auto tick_count = GetTickCount();

		if (tick_count >= last_tickcount + 1000) {
			next_random_delay = delays[rand() % 32];
			last_tickcount = tick_count;
		}

		Sleep(10);
	}
	printf("           .");
	Sleep(1200);
	printf("           ..");
	Sleep(1200);
	printf("           ...");
	Sleep(1200);
	printf("           destructed.");
	Sleep(2000);
	exit(0);
    // placebo
}

// this checks if the game was closed while using the clicker
void mineCheck(void) {
	HWND hwnd1 = FindWindow("LWJGL", NULL);
	while (true) {
		while (!FindWindow((xor ("LWJGL")), nullptr))
		{
			exit(-1);
		}
	}
}