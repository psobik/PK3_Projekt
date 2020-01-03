#include "TxtFile.h"

using namespace std;

bool TxtFile::ifFileTxt() {
	string end = fileName.substr(fileName.length() - 4, 4);
	if (end == ".txt") {
		return true;
	}
	return false;
}

bool TxtFile::ifFileNotEmpty(fstream* inputFile) {
	if (inputFile->good()) {
		inputFile->seekp(0, ios::end);
		size_t size = inputFile->tellg();
		return size > 0;
	}
	return false;
}

TxtFile::~TxtFile() {

}

list<string> TxtFile::readFromFile() {
	ifstream inputFile;
	list<string> wordsFromFile;

	inputFile.open(fileName);

	string word;
	while (inputFile >> word) {
		wordsFromFile.push_back(word);
	}

	inputFile.close();
	return wordsFromFile;
}

void TxtFile::writeToFile(list<string> listToWrite) {
	ofstream outputFile;

	outputFile.open(fileName);

	for (string word : listToWrite) {
		outputFile << word << endl;
	}

	outputFile.close();
}

TxtFile::TxtFile(string fileName)
{
	this->fileName = fileName;
}

list<string> TxtFile::isReadyToRead() {
	fstream file;
	list<string> errors;

	file.open(fileName, ios::in);

	if (!ifFileNotEmpty(&file)) {
		errors.push_back("Input file is empty or does not exist");
	}
	if (!ifFileTxt()) {
		errors.push_back("Input file is not .txt");
	}
	file.close();
	return errors;
}

list<string> TxtFile::isReadyToWrite() {
	fstream file;
	list<string> errors;

	file.open(fileName, ios::out);

	if (ifFileNotEmpty(&file)) {
		errors.push_back("Output file is not empty");
	}
	if (!ifFileTxt()) {
		errors.push_back("Output file is not .txt");
	}
	file.close();
	return errors;
}