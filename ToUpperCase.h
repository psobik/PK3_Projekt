#pragma once
#include "AbstractOperation.h"

class ToUpperCase : public AbstractOperation
{
public:
	virtual string applyOperation(string word) override;
	virtual string getName() override;
	virtual int getTimesPerformed() override;
	virtual void incrementTimesPerformed() override;
};