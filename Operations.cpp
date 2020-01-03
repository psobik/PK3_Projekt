#include "Operations.h"
#include "OnlyFirstLetter.h"
#include "ReplaceLetterAWithLetterB.h"
#include "ToLowerCase.h"
#include "ToUpperCase.h"
#include "WordToTenLetters.h"
#include "WordToThreeLetters.h"

Operations::Operations() {
	systemOperations.push_back(new OnlyFirstLetter());
	systemOperations.push_back(new ReplaceLetterAWithLetterB());
	systemOperations.push_back(new ToLowerCase());
	systemOperations.push_back(new ToUpperCase);
	systemOperations.push_back(new WordToTenLetters());
	systemOperations.push_back(new WordToThreeLetters());
}

Operations::~Operations()
{
}

list<AbstractOperation*> Operations::getOperationsList() {
	return systemOperations;
}

/*map<string, int> Operations::countOperation(list<string> operationList) {
	map<string, int> operationCount;

	int operationCount = 0;

	for (string operation : operationList) {
		operation = 1;
	}

	return operationCount;
}*/

list<AbstractOperation*> Operations::getMethodsForUsage(list<string> choosenOperations) {
	list<AbstractOperation*> choosenSystemOperations;
	for (string operation : choosenOperations) {
		for (AbstractOperation* systemOperation : systemOperations) {
			if (operation == systemOperation->getName()) {
				choosenSystemOperations.push_back(systemOperation);
			}
		}
	}
	return choosenSystemOperations;
}

list<string> Operations::doChoosenOperations(list<AbstractOperation*> choosenSystemOperations, list<string> wordsList) {
	list<string> transformedWords;
	for (string word : wordsList) {
		for (AbstractOperation* choosenSystemOperation : choosenSystemOperations) {
			word = choosenSystemOperation->applyOperation(word);
			choosenSystemOperation->incrementTimesPerformed();
		}
		transformedWords.push_back(word);
	}
	return transformedWords;
}