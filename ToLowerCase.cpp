#include "ToLowerCase.h"

string ToLowerCase::applyOperation(string word)
{
	for (char &character : word) {
		character = tolower(character);
	}
	return word;
}