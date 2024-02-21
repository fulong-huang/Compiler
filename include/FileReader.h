#pragma once
#include <fstream>

class FileReader{
public:
	FileReader(std::string in = "tests/inputs/testIn.txt");
	~FileReader();

	char get();
	void eat();
	void removeSpaces();
	bool isSpace();
	bool isLetter();
	bool isDigit();

	int getNum();

private:
	std::ifstream inputFile;
	FileReader(const FileReader& f);
	FileReader operator=(const FileReader& f);

	int currIdx;
	std::string currLine;


};

