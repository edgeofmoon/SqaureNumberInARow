#pragma once

#include <vector>
#include <string>

class SquareNumbersOnPath
{
public:
	SquareNumbersOnPath();
	~SquareNumbersOnPath();

	// solve and print the permutation of numbers from start to end, inclusive
	// so that every two consecutive numbers sum up to a perfect square number
	void SolveAndPrint(int start, int end);

private:

	// test if the input @num is a perfect square number
	bool isPerfectSquareNumber(int num);

	// print all the numbers in @path
	void printPath(std::vector<int>& path);

	// a recursive depth first exaustive search on the @graph
	// index i in @graph index to the actual number i+@start
	// @size is the total number the final @path should contain
	// @path is the visited path from previous steps
	// @visited tells if i+@start has been visited before
	long long exaustiveSearch(std::vector<std::vector<int>>& graph, int start, int size,
		std::vector<int>& path, std::vector<bool>& visited);

	// message to be printed when no answer is found
	static std::string emptyAnswerStr;

};

