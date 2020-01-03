#pragma once
#include <string>
using namespace std;

class AbstractOperation
{
public:
	int timesPerformed = 0;
	virtual int getTimesPerformed() = 0;
	virtual string getName() = 0;
	virtual string applyOperation(string word) = 0;
	virtual void incrementTimesPerformed() =0;
};