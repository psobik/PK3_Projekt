#pragma once
#include <string>
#include <list>
#include "AbstractOperation.h"

using namespace std;
class Report
{

public:
	void generate(list<AbstractOperation*> choosenSystemOperation);
	Report();
	~Report();
	
};