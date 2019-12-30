#pragma once
#include "AbstractOperation.h"

class WordToThreeLetters : public AbstractOperation
{
		virtual string applyOperation(string word) override;

};