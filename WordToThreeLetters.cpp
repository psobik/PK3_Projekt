#include "WordToThreeLetters.h"

string WordToThreeLetters::applyOperation(string word)
{
	if (word.length() > 3) {
		word.erase(word.begin() + 3, word.end());
		timesPerformed++;
		return word;
	}
	else {
		word.insert(word.end(), (3 - word.length()), 'a');
		timesPerformed++;
		return word;
	}
}

string WordToThreeLetters::getName(){
	return "wordToThreeLetters";
}

int WordToThreeLetters::getTimesPerformed() {
	return timesPerformed;
}

void WordToThreeLetters::incrementTimesPerformed() {
	timesPerformed++;
}