#include "IOUtils.h"

using namespace std;

bool IOUtils::ifFileTxt() {
	string end = fileName.substr(fileName.length() - 4, 4);
	if (end == ".txt") {
		return true;
	}
	return false;
}

bool IOUtils::ifFileNotEmpty(fstream* inputFile) {
	if (inputFile->good()) {
		inputFile->seekp(0, ios::end);
		size_t size = inputFile->tellg();
		return size > 0;
	}
	return false;
}

IOUtils::~IOUtils() {

}

list<string> IOUtils::readFromFile() {
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

void IOUtils::writeToFile(list<string> listToWrite) {
	ofstream outputFile;

	outputFile.open(fileName);

	for (string word : listToWrite) {
		outputFile << word << endl;
	}

}

IOUtils::IOUtils(string fileName)
{
	this->fileName = fileName;
}

list<string> IOUtils::isReadyToRead() {
	fstream file;
	list<string> errors;

	file.open(fileName, ios::in);

	if (!ifFileNotEmpty(&file)) {
		errors.push_back("Empty file");
	}
	if (!ifFileTxt()) {
		errors.push_back("File is not .txt");
	}
	file.close();
	return errors;
}

list<string> IOUtils::isReadyToWrite() {
	fstream file;
	list<string> errors;

	file.open(fileName, ios::out);

	if (ifFileNotEmpty(&file)) {
		errors.push_back("File is not empty");
	}
	if (!ifFileTxt()) {
		errors.push_back("File is not .txt");
	}
	file.close();
	return errors;
}