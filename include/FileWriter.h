#pragma once
#include <fstream>
#include <iostream>

class FileWriter{
public:
	FileWriter(std::string out = "tests/outputs/testOut.txt");
	~FileWriter();

private:
	std::ifstream outputFile;
	FileWriter(const FileWriter& f);
	FileWriter operator=(const FileWriter& f);
};

