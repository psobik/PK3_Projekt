#pragma once
#include "AbstractOperation.h"

class ReplaceLetterAWithLetterB : public AbstractOperation
{
	virtual string applyOperation(string word) override;
};