#include<iostream>
#include<vector>
#include<string>
#include"log.hpp"
#include"nogui.hpp"
/*
Conversion method:
All arrays will be converted into int aguments which it will be used in a switch method:



*/

std::vector<std::string> commands{"--nogui", "--gui" "test"};
std::vector<std::string>  usr_input{"--nogui"};

int main(int argc, char* argv[]) {
	for (int i=0 ; i < argc; i++) {
		std::string agument = argv[i];
		if (agument.find(".exe") == std::string::npos) {
			usr_input.push_back(agument);
		}
	}
	switch (usr_input[1] == "--gui")
	{
	case 1:
		interpret();
		break;
	default:
		break;
	}

	return 0;
}