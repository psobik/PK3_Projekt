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
	
	
public:
	void setInputFileName(string name);
	void setOutputFileName(string name);
	void setOperationList(string operation);
	string getInputFileName();
	string getOutputFileName();
	list<string> getOperationList();
	bool operationExist(string name);
	ConsoleParams(int argNumber, char** argument);
	~ConsoleParams();
	
};

