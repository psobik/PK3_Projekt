#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

using namespace std;

struct OperationList {
	string operationName;
	OperationList* next;
};

struct ConsoleParams {
	string inputFileName;
	string outputFileName;
	list<string> operationList;
};

struct TransformedWord {
	string word;
	TransformedWord* next;
};

void displayHelp() {
	cout << "\n \n Maybe you need some help? \n" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "| \t To run program you have to use params: \t |"<<endl;
	cout << "| \t -i inputFileName.txt \t \t \t \t |" << endl;
	cout << "| \t -o outputFileName.txt \t \t \t \t |" << endl; 
	cout << "| \t -t operation1 -t operation2 -t oepration3 ... \t |" << endl;
	cout << "| \t List of available operations: \t \t \t |" << endl;

	cout << "----------------------------------------------------------" << endl;
}

list<string> readFromFileToList(string inputName) {
	ifstream inputFile;
	list<string> lineFromFile;

	inputFile.open(inputName);

	if (inputFile.good() == false) {
		cout << "Something went wrong :( " << endl;
		cout << "Check if you wrote correct name of your file... \n";
		displayHelp();
		return lineFromFile;
	}
	else {
		string word;
		while (inputFile >> word) {
			lineFromFile.push_back(word);
		}
		
	}
	inputFile.close();
	return lineFromFile;
}

ConsoleParams* getConsoleParams(int liczbaArg, char** argument) {
	ConsoleParams* consoleParams = new ConsoleParams;

	for (int i = 1; i < liczbaArg; i++) {
		if (argument[i][0] == '-' && strlen(argument[i]) == 2) {
			switch (argument[i][1]) {
			case 'h':
				displayHelp();
				i++;
				break;
			case 'i':
				consoleParams->inputFileName = argument[i + 1];
				i++;
				break;
			case 'o':
				consoleParams->outputFileName = argument[i + 1];
				i++;
				break;
			case 't':
				consoleParams->operationList.push_back(argument[i + 1]);
				i++;
				break;
			}
		}
	}
	return consoleParams;
}

int main(int argc, char** argv)
{

	ConsoleParams* consoleParams;
	consoleParams = getConsoleParams(argc, argv);
	cout << consoleParams->inputFileName << endl;
	cout << "\noperations: " << endl;
	for (string element : consoleParams->operationList){
		cout << element << '\n';
	}
	cout << endl;
	cout << consoleParams->outputFileName << endl;
	list<string> lista = readFromFileToList(consoleParams->inputFileName);
	cout << "\nslowa: " << endl;
	for (string element : lista) {
		cout << element << '\n';
	}

	delete consoleParams;
	_CrtDumpMemoryLeaks();
	return 0;
}