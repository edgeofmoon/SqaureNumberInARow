#include "SquareNumbersOnPath.h"
#include <iostream>
using namespace std;

int defaulTest(){
	SquareNumbersOnPath sol;
	for (int start = 1; start < 20; start++){
		for (int end = start + 2; end <= start + 20; end++){
			cout << "Solve for " << start << " to " << end << endl;
			sol.SolveAndPrint(start, end);
		}
	}
}

int main(int argc, char* argv[]){
	if (argc < 3){
		cout << "Usage: " << argv[0] << " start_number end_number" << endl;
		defaulTest();
	}
	else{
		int start = atoi(argv[1]);
		int end = atoi(argv[2]);
		SquareNumbersOnPath sol;
		sol.SolveAndPrint(start, end);
	}

	char c;
	cin >> c;
}