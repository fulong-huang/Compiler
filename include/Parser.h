#include "FileReader.h"

class Parser{
public:
	Parser(FileReader* f);
	~Parser();

	void run();

private:
	Parser(Parser& p);
	Parser operator=(const Parser& p);

	FileReader* fd;

	int relOp();
	void ident();
	int number();
};

