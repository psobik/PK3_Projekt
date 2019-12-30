#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include "ConsoleParams.h"
#include "TxtFile.h"

using namespace std;

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

void writeFromListToFile(string outputName, list<string> listToWrite) {
	ofstream outputFile;

	outputFile.open(outputName);

	for (string word : listToWrite) {
		outputFile << word << endl;
	}

}

string replaceLetterAWithLetterB(string word) {
	word.replace(word.begin(), word.end(), 'a', 'b');
	return word;
}

string toLowerCase(string word) {
	for (char& character : word) {
		character = tolower(character);
	}
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
	ConsoleParams consoleParams(argc, argv);

	/*cout << "operations: " << endl;
	for (string element : consoleParams.getOperationList()) {
		cout << element << '\n';
	}
	*/
	cout << endl;

	TxtFile fileToRead(consoleParams.getInputFileName());
	
	list<string> errors = fileToRead.isReadyToRead();
	if (errors.size() > 0) {
		for (string element : errors) {
			cout << element << endl;
			displayHelp();
			return 0;
		}
	}
	
	list<string> words = fileToRead.readFromFile();
	
	/*for (string element : words) {
		cout << element << endl;
	}*/

	list<string> transformedWord = transformText(consoleParams.getOperationList(), words);

	for (string element : transformedWord) {
		cout << element << '\n';
	}

	writeFromListToFile(consoleParams.getOutputFileName(),transformedWord);

	_CrtDumpMemoryLeaks();
	return 0;
}