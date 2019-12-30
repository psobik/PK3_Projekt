#pragma once
#include "AbstractOperation.h"

class ToLowerCase :	public AbstractOperation
{
	virtual string applyOperation(string word) override;
};