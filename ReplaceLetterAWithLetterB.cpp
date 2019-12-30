#include "ReplaceLetterAWithLetterB.h"

string ReplaceLetterAWithLetterB::applyOperation(string word) {
	word.replace(word.begin(), word.end(), 'a', 'b');
	return word;
}

