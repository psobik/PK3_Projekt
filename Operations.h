#pragma once
#include <list>
#include "AbstractOperation.h"

class Operations
{
	list<AbstractOperation*> systemOperations;

public:
	
	list<AbstractOperation*> getOperationsList();
	list<AbstractOperation*> getMethodsForUsage(list<string> operations);
	list<string> doChoosenOperations(list<AbstractOperation*> choosenSystemOperations, list<string> wordsList);
	
	Operations();
	~Operations();
	
};