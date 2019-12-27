#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void openFile(string inputName, string outputName) {
	ifstream inputFile;
	ofstream outputFile;
	inputFile.open(inputName);
	outputFile.open(outputName);

	if (inputFile.good() == true) {
		string line;
		while (!inputFile.eof())
		{
			getline(inputFile, line);
			outputFile << line << endl;
		}	
	}
	else {
		cout << "Something went wrong :( Check if you wrote correct name... \n";
	}
	inputFile.close();
	outputFile.close();
}

int main()
{
	openFile("inputFile.txt","outputFile.txt");
	

	return 0;
}