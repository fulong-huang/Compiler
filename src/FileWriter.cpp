#include "FileWriter.h"

FileWriter::FileWriter(std::string out){
	std::cout << "Init FileWriter" << std::endl;

	outputFile.open(out, std::fstream::in | std::fstream::out | std::fstream::trunc);
	if(outputFile.is_open()){
		std::cout << "open write successful" << std::endl;
	}
	else{
		std::cout << "File " << out << " Failed to Open!!!" << std::endl;
		abort();
	};
	
};

FileWriter::~FileWriter(){
	outputFile.close();
	std::cout << "FileWriter Destroyed" << std::endl;
};


