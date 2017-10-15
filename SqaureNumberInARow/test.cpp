#include "SquareNumbersOnPath.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void defaulTest(){
	SquareNumbersOnPath sol;
	for (int start = 1; start < 2; start++){
		for (int end = start + 2; end <= start + 20; end++){
			cout << "Solve for " << start << " to " << end << endl;
			sol.SolveAndPrint(start, end);
		}
	}
}

int main(int argc, char* argv[]){
	if (argc < 3){
		cout << "Usage: " << argv[0] << " start_number end_number" << endl;
		cout << "Running default test cases." << endl;
		defaulTest();
	}
	else{
		int start = atoi(argv[1]);
		int end = atoi(argv[2]);
		if (start < 0) {
			cout << "Numbers must be positive!" << endl;
			return 0;
		}
		if (start >= end){
			cout << "Range must be positive!" << endl;
			return 0;
		}
		SquareNumbersOnPath sol;
		cout << "Solve for " << start << " to " << end << endl;
		sol.SolveAndPrint(start, end);
	}
	return 1;
}