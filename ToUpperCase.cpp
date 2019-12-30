#include "ToUpperCase.h"

string ToUpperCase::applyOperation(string word)
{
	for (char& character : word) {
		character = toupper(character);
	}
	return word;
}