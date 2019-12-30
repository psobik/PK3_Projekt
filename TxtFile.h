#pragma once
#include <string>
#include <list>
#include <fstream>

using namespace std;

class TxtFile
{
	string fileName;

	bool ifFileTxt();
	bool ifFileNotEmpty(fstream* inputFile);

public:
	list<string> isReadyToRead();
	list<string> isReadyToWrite();

	list<string> readFromFile();
	void writeToFile(list<string> listToWrite);

	TxtFile(string fileName);
	~TxtFile();
};