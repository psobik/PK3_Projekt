#include "WordToTenLetters.h"

string WordToTenLetters::applyOperation(string word) {
	if (word.length() < 10) {
		word.insert(word.end(), (10 - word.length()), 'a');
		return word;
	}
	else {
		word.erase(word.begin() + 10, word.end());
		return word;
	}
}