#include<iostream>
#include<vector>
#include<string>
#include"agument handling.hpp"


/*
Conversion method:
All arrays will be converted into int aguments which it will be used in a switch method:



*/

std::vector<std::string> commands{"--nogui", "--gui" "test"};
std::vector<std::string>  usr_input{"lublu.exe", "--gui"};

int main(int argc, char* argv[]) {
	add_defintions(commands);
	if (false) {
		usr_input.push_back("--nogui");
	}

	else{
		for(int transition = 0; transition < argc-1; transition++) {
			if (argv[transition] != "lublu.exe") {
				usr_input.push_back(argv[transition]);
			}
		}
	}
	std::cout << convert_agument(usr_input[0]);

	switch (convert_agument(usr_input[0])) {
	case 1:
		std::cout << "no gui mode" << std::endl;
		break;
	case 2:
		std::cout << "gui mode" << std::endl;
		break;

	}
	void remove_defintions();

	
	return 0;
}