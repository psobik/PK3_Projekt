#pragma once
#include <string>
using namespace std;

class AbstractOperation
{
public:
	virtual string applyOperation(string word) = 0;
};