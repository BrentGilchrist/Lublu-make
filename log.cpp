#include<iostream>
#include<fstream>
#include<vector>


std::vector<std::string> past_logs{};


void log(std::string text) {
	std::ofstream Logfile("Logs.txt");
	past_logs.push_back(text);
	for(std::string every_text : past_logs){
		Logfile << every_text << std::endl;
	}
	Logfile.close();
}

