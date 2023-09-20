#include<iostream>
#include<string>



//I guess this works lol, thus makes the code shorter right???????
#ifdef _WIN32
	#include "cmd_windows.hpp"
#elif __linux__
	#include "terminal_linux.hpp"
#endif

std::string when_quit;
void interpret() {
	while (true)
	{
		
		std::cout << get_row() << get_column();
		std::cin >> when_quit;
		if (when_quit == "quit") {
			break;
		}
	}
}