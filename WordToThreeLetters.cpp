#include "WordToThreeLetters.h"

string WordToThreeLetters::applyOperation(string word)
{
	if (word.length() > 3) {
		word.erase(word.begin() + 3, word.end());
		return word;
	}
	else {
		word.insert(word.end(), (3 - word.length()), 'a');
		return word;
	}
}