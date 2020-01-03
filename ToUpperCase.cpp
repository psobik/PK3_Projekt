#include "ToUpperCase.h"

string ToUpperCase::applyOperation(string word)
{
	for (char& character : word) {
		character = toupper(character);
	}
	timesPerformed++;
	return word;
}

string ToUpperCase::getName(){
	return "toUpperCase";
}

int ToUpperCase::getTimesPerformed() {
	return timesPerformed;
}

void ToUpperCase::incrementTimesPerformed() {
	timesPerformed++;
}