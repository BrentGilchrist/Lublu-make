#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>

#include<numeric>
#include <wchar.h>
#include <locale.h>
#include <fcntl.h>
#include <io.h>
//I guess this works lol, thus makes the code shorter right???????
#ifdef _WIN32
	#include "CMD_windows.hpp"
#elif __linux__
	#include "terminal_linux.hpp"
#endif


struct Line {

	bool isSpecial = false;
	std::vector<std::string> arrstr{};
	std::vector<const wchar_t*> arrcwcp{};
	void push_back(std::string strC="", const wchar_t* cwcp= L"") {
		if (not isSpecial) {
			arrcwcp.push_back(cwcp);
		}
		else if (isSpecial) {
			arrstr.push_back(strC);

		}
	}
	void pop_back(std::string strC = "", const wchar_t* cwcp = L"") {
		if (not isSpecial) {
			arrcwcp.pop_back();
		}
		else if (isSpecial) {
			arrstr.pop_back();

		};

	}
	void resize(int num) {

		if (not isSpecial) {
			arrcwcp.resize(num);
		}
		else if (isSpecial) {
			arrstr.resize(num);

		};
	}
	
};




void console_interface() {
	std::vector<Line> screen{};
	_setmode(_fileno(stdout), _O_U16TEXT);
	screen.resize(2);
	screen[0].isSpecial, screen[1].isSpecial = true;
	for (int i = 0; i < get_column(); i++) {
		screen[0].push_back("", L"\x2588");
	}
	screen[1] = screen[0];
	for (Line row : screen) {
		for (const wchar_t* px: row.arrcwcp) {
			wprintf_s(px);
		}
		wprintf_s(L"\n");
	}
	
	
}






void interpret() {
	while (true)
	{
		console_interface();
		std::string when_quit;

		std::cin >> when_quit;
		if (when_quit == "quit") {
			break;
		}
	}
}