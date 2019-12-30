#pragma once
#include "AbstractOperation.h"

class WordToTenLetters : public AbstractOperation
{
	virtual string applyOperation(string word) override;
};