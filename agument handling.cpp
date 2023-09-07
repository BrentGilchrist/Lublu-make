#include <iostream>
#include <vector>
#include <array>
#include <string>

/*
This just a simple id system for aguments that has been pass through cmd and makes switching alot more simpler than before.
Yes I have tried classes but this doesn't need a class unless I want the variable to reset.
*/
std::vector<std::string> agument_definition{};
std::vector<std::int8_t> agument_id{};
std::vector<std::string> usr_input{};

int default_id = 1;




int convert_agument(std::string agument) {


	for (int transistion = 0; transistion < std::stoi(std::to_string(agument_definition.size())); transistion++) {
		if (agument == agument_definition[transistion]) {
			return agument_id[transistion];
		}
	}
	return 0;
}
std::vector<int> process_input(std::vector<std::string> the_input) {
	std::vector<std::string> result{};
	std::vector<int> final_result{};
	for (std::string text : the_input) {
		if (text.find(".exe") == std::string::npos) {
			result.push_back(text);
		}
	}
	int length = result.size();
	for (int transition = 0; transition < lengt; transition++) {
		final_result.push_back(convert_agument(result[transition]));
	}
	return final_result;

}
void print_defintions() {
	int length = agument_definition.size();
	std::vector<std::string> Output;
	for (int transistion = 0; transistion < length; transistion++) {
		Output.push_back(agument_definition[transistion]);
		int id = agument_id[transistion];
		Output.push_back(std::to_string(id));
	}
	length = Output.size();
	for (int transistion = 0; transistion < length; transistion += 2) {
		std::cout << Output[transistion] << " " << Output[transistion + 1] << std::endl;
	}

};

void add_defintion(std::string agument, int custom_id = 0) {
	agument_definition.push_back(agument);
	if (custom_id > 0) {
		agument_id.push_back(custom_id++);
		default_id = custom_id;
	}
	else {
		agument_id.push_back(default_id++);
	};
}
void add_defintions(std::vector<std::string> aguments) {

	int length = aguments.size();
	for (int transition = 0; transition < length+1; transition++) {
		add_defintion(aguments[transition]);
	}
}

void remove_defintions() {
	agument_id.clear();
	agument_definition.clear();
}




