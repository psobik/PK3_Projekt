#pragma once
#include "AbstractOperation.h"

class ToUpperCase : public AbstractOperation
{
	virtual string applyOperation(string word) override;
};