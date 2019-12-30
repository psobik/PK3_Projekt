#include "ConsoleParams.h"

string ConsoleParams::getInputFileName() {
	return inputFileName;
}

string ConsoleParams::getOutputFileName() {
	return outputFileName;
}

list<string> ConsoleParams::getOperationList() {
	return operationList;
}

bool ConsoleParams::operationExist(string operationToCheck) {
	for (int i = 0; i < operationsSize; i++) {
		if (operations[i] == operationToCheck) {
			return true;
		}
	}
	return false;
}

ConsoleParams::ConsoleParams(int argNumber, char** argument) {
	displayHelp = false;
	for (int i = 1; i < argNumber; i++) {
		if (argument[i][0] == '-' && strlen(argument[i]) == 2) {
			switch (argument[i][1]) {
			case 'h':
				displayHelp = true;
				i++;
				break;
			case 'i':
				inputFileName = argument[i + 1];
				i++;
				break;
			case 'o':
				outputFileName = argument[i + 1];
				i++;
				break;
			case 't':
				if (operationExist(argument[i + 1])) {
					operationList.push_back(argument[i + 1]);
				}
				i++;
				break;
			}
		}
	}
}

ConsoleParams::~ConsoleParams()
{
}
