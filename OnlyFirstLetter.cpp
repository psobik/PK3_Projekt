#include "OnlyFirstLetter.h"
#include <algorithm>

string OnlyFirstLetter::applyOperation(string word) {
	word.erase(1);
	return word;
}

string OnlyFirstLetter::getName() {
	return "onlyFirstLetter";
}

int OnlyFirstLetter::getTimesPerformed() {
	return timesPerformed;
}

void OnlyFirstLetter::incrementTimesPerformed() {
	timesPerformed++;
}