#include "Report.h"
#include <iostream>
#include <string>
#include <list>
#include "Operations.h"

using namespace std;

void Report::generate(list<AbstractOperation*> operations) {
	
	cout << "\n\n###################### REPORT ############################\n" << endl;
	for (AbstractOperation* operation : operations) {
		cout << "Operation: " << operation->getName() << " performed: " << operation->getTimesPerformed() << " times." << endl;
	}
}

Report::Report() {

}

Report::~Report(){
}