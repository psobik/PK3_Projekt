#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

using namespace std;

struct ConsoleParams {
	string inputFileName;
	string outputFileName;
	list<string> operationList;
};

static const struct Operations {
	static const int operationsSize = 5;
	string operations[operationsSize] = { "replaceLetterAWithLetterB", "toLowerCase", "toUpperCase", "wordToThreeLetters", "wordToTenLetters" };
};

void displayHelp() {
	cout << "\n \n Maybe you need some help? \n" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "| \t To run program you have to use params: \t |" << endl;
	cout << "|\t\t\t\t\t\t\t |" << endl;
	cout << "| \t -h <it shows this block of help> \t \t |" << endl;
	cout << "| \t -i inputFileName.txt \t \t \t \t |" << endl;
	cout << "| \t -o outputFileName.txt \t \t \t \t |" << endl;
	cout << "| \t -t operation1 -t operation2 -t oepration3 ... \t |" << endl;
	cout << "|\t\t\t\t\t\t\t |" << endl;
	cout << "| \t Your file has to have correct format.  \t |" << endl;
	cout << "| \t Do not use polish diacritical marks.  \t \t |" << endl;
	cout << "|\t\t\t\t\t\t\t |" << endl;
	cout << "|\t\t\t\t\t\t\t |" << endl;
	cout << "| \t List of available operations: \t \t \t |" << endl;
	cout << "|\t\t\t\t\t\t\t |" << endl;
	cout << "| \t * replaceLetterAWithLetterB \t \t \t |" << endl;
	cout << "| \t * toLowerCase \t \t \t \t \t |" << endl;
	cout << "| \t * toUpperCase \t \t \t \t \t |" << endl;
	cout << "| \t * wordToThreeLetters \t \t \t \t |" << endl;
	cout << "| \t * wordToTenLetters \t \t \t \t |" << endl;
	cout << "----------------------------------------------------------" << endl;
}

string trimWord(string word) {

	char charToTrim[] = { '!', ',', '.', ';', ':', '?', ' ', '\n', '\t', '(', ')' };

	for (int i = 0; i < sizeof(charToTrim); i++) {
		word.erase(std::remove(word.begin(), word.end(), charToTrim[i]), word.end());
	}
	return word;
}

list<string> trimmedWords(list<string> wordList) {

	list<string> trimmedWords;

	for (string word : wordList) {
		word = trimWord(word);
		trimmedWords.push_back(word);
	}
	return trimmedWords;
}

list<string> readFromFileToList(string inputName) {

	ifstream inputFile;
	list<string> wordsFromFile;

	inputFile.open(inputName);

	if (inputFile.good() == false) {
		cout << "Something went wrong :( " << endl;
		cout << "Check if you wrote correct name of your file... \n";
		displayHelp();
		return wordsFromFile;
	}
	else {
		string word;
		while (inputFile >> word) {
			wordsFromFile.push_back(word);
		}
	}
	inputFile.close();

	return wordsFromFile;
}

void writeFromListToFile(string outputName, list<string> listToWrite) {
	ofstream outputFile;

	outputFile.open(outputName);

	for (string word : listToWrite) {
		outputFile << word << "\n";
	}

}

bool operationExist(string operationToCheck) {
	Operations* operations = new Operations;
	for (int i = 0; i < operations->operationsSize; i++) {
		if (operations->operations[i] == operationToCheck) {
			return true;
		}
	}
	return false;
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
				if (operationExist(argument[i + 1]) == true) {
					consoleParams->operationList.push_back(argument[i + 1]);
				}
				i++;
				break;
			}
		}
	}
	return consoleParams;
}

string replaceLetterAWithLetterB(string word) {
	word.replace(word.begin(), word.end(), 'a', 'b');
	return word;
}

string toLowerCase(string word) {
	for_each(word.begin(), word.end(), [](char& c) {
		c = ::tolower(c);
		});
	return word;
}

string toUpperCase(string word) {
	for_each(word.begin(), word.end(), [](char& c) {
		c = ::toupper(c);
		});
	return word;
}

string wordToThreeLetters(string word) {
	if (word.length() > 3) {
		word.erase(word.begin() + 3, word.end());
		return word;
	}
	else {
		word.insert(word.end(), (3 - word.length()), 'a');
		return word;
	}
}

string wordToTenLetters(string word) {
	if (word.length() < 10) {
		word.insert(word.end(), (10 - word.length()), 'a');
		return word;
	}
	else {
		word.erase(word.begin() + 10, word.end());
		return word;
	}
}

list<string> transformText(list<string> operationList, list<string> wordsList) {

	list<string> transformedWords;
	string changedWord;

	for (string word : wordsList) {
		for (string operation : operationList) {
			if (operation == "replaceLetterAWithLetterB") {
				word = replaceLetterAWithLetterB(word);
			}
			if (operation == "toLowerCase") {
				word = toLowerCase(word);
			}
			if (operation == "toUpperCase") {
				word = toUpperCase(word);
			}
			if (operation == "wordToThreeLetters") {
				word = wordToThreeLetters(word);
			}
			if (operation == "wordToTenLetters") {
				word = wordToTenLetters(word);
			}
		}
		transformedWords.push_back(word);
	}
	return transformedWords;
}


int main(int argc, char** argv)
{

	ConsoleParams* consoleParams;
	consoleParams = getConsoleParams(argc, argv);

	cout << consoleParams->inputFileName << endl;
	cout << consoleParams->outputFileName << endl;

	cout << "\n\noperations: " << endl;
	for (string element : consoleParams->operationList) {
		cout << element << '\n';
	}
	cout << endl;

	list<string> wordsFromFile = readFromFileToList(consoleParams->inputFileName);

	list<string> trimmedWordsFromFile = trimmedWords(wordsFromFile);

	list<string> transformedWord = transformText(consoleParams->operationList, trimmedWordsFromFile);

	for (string element : transformedWord) {
		cout << element << '\n';
	}

	writeFromListToFile(consoleParams->outputFileName,transformedWord);
	delete consoleParams;
	_CrtDumpMemoryLeaks();
	return 0;
}