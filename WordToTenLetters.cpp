#include "WordToTenLetters.h"

string WordToTenLetters::applyOperation(string word) {
	if (word.length() < 10) {
		word.insert(word.end(), (10 - word.length()), 'a');
		timesPerformed++;
		return word;
	}
	else {
		word.erase(word.begin() + 10, word.end());
		timesPerformed++;
		return word;
	}
}

string WordToTenLetters::getName(){
	return "wordToTenLetters";
}

int WordToTenLetters::getTimesPerformed() {
	return timesPerformed;
}

void WordToTenLetters::incrementTimesPerformed() {
	timesPerformed++;
}