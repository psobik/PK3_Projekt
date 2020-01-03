#include "Help.h"
#include "Operations.h"

using namespace std;

void Help::displayHelp() {
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

void Help::programSummary(string outputfileName) {
	cout << "\n\n\n###################### DONE ##############################" << endl;
	cout << "\nYou can find the results in your outputfile: " << outputfileName << endl;
}

void Help::displayErrors(list<string> errors) {
	if (errors.size() > 0) {
		cout << "\n\n\n###################### ERRORS ##############################" << endl;
		for (string element : errors) {
			cout << element << endl;
			displayHelp();
			exit(0);
		}
	}
}

Help::Help()
{
}

Help::~Help()
{
}
