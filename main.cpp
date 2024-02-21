#include <iostream>
#include "FileReader.h"
#include "Parser.h"

int main(){
	std::cout << "Hello World!" << std::endl;
	FileReader* f = new FileReader();
	Parser p(f);
	p.run();
	
	delete f;
	return 0;
};

