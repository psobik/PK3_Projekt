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

public:
	string getInputFileName();
	string getOutputFileName();
	list<string> getOperationList();
	bool ifDisplayHelp();
	
	ConsoleParams(int argNumber, char** argument);
	~ConsoleParams();
};

