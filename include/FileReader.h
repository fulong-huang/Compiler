#pragma once

class FileReader{
public:
	FileReader();
	~FileReader();

private:
	FileReader(const FileReader& f);
	FileReader operator=(const FileReader& f);
};

