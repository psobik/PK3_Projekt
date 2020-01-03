#include "ReplaceLetterAWithLetterB.h"

string ReplaceLetterAWithLetterB::applyOperation(string word) {
	word.replace(word.begin(), word.end(), 'a', 'b');
	timesPerformed++;
	return word;
}

string ReplaceLetterAWithLetterB::getName() {
	return "replaceLetterAWithLetterB";
}

int ReplaceLetterAWithLetterB::getTimesPerformed() {
	return timesPerformed;
}

void ReplaceLetterAWithLetterB::incrementTimesPerformed() {
	timesPerformed++;
}