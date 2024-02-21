#include <iostream>
#include "FileReader.h"

FileReader::FileReader(std::string in){
	std::cout << "Init FileReader" << std::endl;

	// Open input file
	inputFile.open(in, std::fstream::in);
	if(inputFile.is_open()){
		std::cout << "open read successful" << std::endl;
	}
	else{
		std::cout << "File " << in << " Failed to Open!!!" << std::endl;
		abort();
	};
	
	// Read input file
	if(inputFile.eof()){
		std::cout << "EMPTY FILE: " << in << std::endl;
		currLine = "\0";
	}
	else{
		getline(inputFile, currLine);
	};
	currIdx = 0;

};

FileReader::~FileReader(){
	inputFile.close();
	std::cout << "FileReader Destroyed" << std::endl;
};

char FileReader::get(){
	if(currIdx == -1){
		return '\0';
	};
	return currLine[currIdx];
};

void FileReader::eat(){
	// increment index,
	// remove all following spaces
	currIdx++;
	if(currIdx >= currLine.size()){
		currIdx = -1;
	};
};

void FileReader::removeSpaces(){
	while(isSpace()){
		currIdx++;
		if(currIdx >= currLine.size()){
			if(inputFile.eof()){
				currIdx = 0;
				currLine = "\0";
				break;
			};
			getline(inputFile, currLine);
			currIdx = 0;
		};
	};
};

bool FileReader::isSpace(){
	return currLine[currIdx] == ' ' || 
		currLine[currIdx] == '\0' || 
		currLine[currIdx] == '\t';
};
bool FileReader::isLetter(){
	return currLine[currIdx] >= 'a' && currLine[currIdx] <= 'z' || 
		currLine[currIdx] >= 'A' && currLine[currIdx] <= 'Z';
}
bool FileReader::isDigit(){
	return currLine[currIdx] >= '0' && currLine[currIdx] <= '9';
};

int FileReader::getNum(){
	int result = 0;
	while(isDigit()){
		result *= 10;   // Potential out of bound
		result += currLine[currIdx];
		eat();
	};
	if(!isSpace()){
		std::cout << "Invalid Syntax, invalid token found after number" << std::endl;
		abort();
	};
	return result;
};
