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
#define _CRTDBG_MAP_ALLOC 

using namespace std;

void displayHelp() {
	Operations systemOperations;
	cout << "\n \n Maybe you need some help? \n" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "|          To run program you have to use params:        |" << endl;
	cout << "|                                                        |" << endl;
	cout << "| -h <it shows this block of help>                       |" << endl;
	cout << "| -i inputFileName.txt                                   |" << endl;
	cout << "| -o outputFileName.txt                                  |" << endl;
	cout << "| -t operation1 -t operation2 -t oepration3 ...          |" << endl;
	cout << "|                                                        |" << endl;
	cout << "|                                                        |" << endl;
	cout << "| Your file has to have correct format.                  |" << endl;
	cout << "| Do not use polish diacritical marks.                   |" << endl;
	cout << "|                                                        |" << endl;
	cout << "|                                                        |" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "\n\n       List of available operations:                  " << endl << endl;
	for (AbstractOperation* operation : systemOperations.getOperationsList()) {
		cout << " *> " << operation->getName() << endl;
	}
	cout << "----------------------------------------------------------" << endl;
}

int main(int argc, char** argv)
{
	ConsoleParams consoleParams(argc, argv);
	
	TxtFile fileToRead(consoleParams.getInputFileName());
	TxtFile fileToWrite(consoleParams.getOutputFileName());
	
	list<string> operationListFromUser = consoleParams.getOperationList();

	Operations operation;
	Report report;

	if (consoleParams.ifDisplayHelp()) {
		displayHelp();
	}

	list<string> errors = fileToRead.isReadyToRead();
	if (errors.size() > 0) {
		cout << "\n\n\n##### ERRORS ####" <<endl;
		for (string element : errors) {
			cout << element << endl;
			displayHelp();
			return 0;
		}
	}

	list<string> words = fileToRead.readFromFile();
	
	list<AbstractOperation*> choosenSystemOperation = operation.getMethodsForUsage(operationListFromUser);
	
	list<string> transformedWords = operation.doChoosenOperations(choosenSystemOperation, words);

	errors = fileToWrite.isReadyToWrite();
	if (errors.size() > 0) {
		cout << "\n\n\n##### ERRORS ####" << endl;
		for (string element : errors) {
			cout << element << endl;
			displayHelp();
			return 0;
		}
	}

	cout << "\n\n\n###################### DONE ##############################" << endl;
	cout << "\nYou can find the results in your outputfile: " << consoleParams.getOutputFileName() << endl;

	report.generate(choosenSystemOperation);

	fileToWrite.writeToFile(transformedWords);

	_CrtDumpMemoryLeaks();
	return 0;
}