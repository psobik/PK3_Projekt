#include "ToLowerCase.h"

string ToLowerCase::applyOperation(string word)
{
	for (char &character : word) {
		character = tolower(character);
	}
	return word;
}

string ToLowerCase::getName(){
	return "toLowerCcase";
}

int ToLowerCase::getTimesPerformed() {
	return timesPerformed;
}

void ToLowerCase::incrementTimesPerformed() {
	timesPerformed++;
}