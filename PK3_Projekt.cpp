#include <iostream>
#include <string>
#include <algorithm>
#include <list> 
#include <stdlib.h>  
#include <crtdbg.h>  
#include <iomanip>
#include "ConsoleParams.h"
#include "TxtFile.h"
#include "Operations.h"
#include "Word.h"
#include "Report.h"
#include "Help.h"
#define _CRTDBG_MAP_ALLOC 

using namespace std;

int main(int argc, char** argv)
{
	Help help;
	ConsoleParams consoleParams(argc, argv);
	string inputfileName = consoleParams.getInputFileName();
	string outputfileName = consoleParams.getOutputFileName();
	bool ifHelp = consoleParams.ifDisplayHelp();
	list<string> operationListFromUser = consoleParams.getOperationList();

	TxtFile fileToRead(inputfileName);
	TxtFile fileToWrite(outputfileName);
	Operations operation;
	Report report;

	if (ifHelp) {
		help.displayHelp();
	}

	list<string> errors = fileToRead.isReadyToRead();

	help.displayErrors(errors);

	list<string> words = fileToRead.readFromFile();
	
	list<AbstractOperation*> choosenSystemOperation = operation.getMethodsForUsage(operationListFromUser);
	
	list<string> transformedWords = operation.doChoosenOperations(choosenSystemOperation, words);

	errors = fileToWrite.isReadyToWrite();
	
	help.displayErrors(errors);

	help.programSummary(consoleParams.getOutputFileName());

	fileToWrite.writeToFile(transformedWords);
	
	report.generate(operation.getOperationsList());
	
	_CrtDumpMemoryLeaks();
	return 0;
}