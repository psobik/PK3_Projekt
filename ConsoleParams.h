#pragma once
#include <string>
#include <list>
using namespace std;

class ConsoleParams
{
	string inputFileName;
	string outputFileName;
	list<string> operationList;
	bool displayHelp;
	static const int operationsSize = 5;
	string operations[operationsSize] = { "replaceLetterAWithLetterB", "toLowerCase", "toUpperCase", "wordToThreeLetters", "wordToTenLetters" };
	bool operationExist(string name);

public:
	string getInputFileName();
	string getOutputFileName();
	list<string> getOperationList();
	
	ConsoleParams(int argNumber, char** argument);
	~ConsoleParams();
};

