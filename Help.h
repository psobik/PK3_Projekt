#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Help
{
public:
	void displayHelp();
	void programSummary(string outputfileName);
	void displayErrors(list<string> errors);
	Help();
	~Help();
};

