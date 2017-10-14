#include "SquareNumbersOnPath.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string SquareNumbersOnPath::emptyAnswerStr = "No answer can be found.";

SquareNumbersOnPath::SquareNumbersOnPath()
{
}


SquareNumbersOnPath::~SquareNumbersOnPath()
{
}


bool SquareNumbersOnPath::isPerfectSquareNumber(int num){
	if (num < 0) return false;
	int t = (int)round(sqrt(num));
	return t*t == num;
}

void SquareNumbersOnPath::printPath(vector<int>& path){
	for (size_t i = 0; i < path.size(); i++){
		cout << path[i] << " ";
	}
	cout << endl;
}

long long SquareNumbersOnPath::exaustiveSearch(vector< vector<int> >& graph, int start, int size,
	vector<int>& path, vector<bool>& visited){
	if (path.size() == size){
		printPath(path);
		return 1;
	}
	long long answer_count = 0;
	vector<int>& neighbors = graph[path.back() - start];
	for (size_t i = 0; i < neighbors.size(); i++){
		if (!visited[neighbors[i] - start]){
			path.push_back(neighbors[i]);
			visited[neighbors[i] - start] = true;
			answer_count += exaustiveSearch(graph, start, size, path, visited);
			path.pop_back();
			visited[neighbors[i] - start] = false;
		}
	}
	return answer_count;
}

void SquareNumbersOnPath::SolveAndPrint(int start, int end){
	// build the neighbor graph
	// vector is more efficient than unordered_map if key is continuous
	int size = end - start + 1;
	vector< vector<int> > graph(size);
	for (int i = start; i < end; i++){
		for (int j = i + 1; j <= end; j++){
			if (isPerfectSquareNumber(i + j)){
				// relationship is symmetrical
				graph[i - start].push_back(j);
				graph[j - start].push_back(i);
			}
		}
	}

	// fast reject if more than 2 numbers have less than 2 neighbors
	// because they have to be put at one of the two ends
	int _num_numbers_with_few_neighbors = 0;
	for (size_t i = 0; i < graph[i].size(); i++){
		if (graph[i].size() < 2){
			_num_numbers_with_few_neighbors++;
			if (_num_numbers_with_few_neighbors > 2){
				// no answers
				cout << emptyAnswerStr << endl;
				return;
			}
		}
	}

	// find all hamiltonian path, which is a NP-complete probelm!
	// source: https://en.wikipedia.org/wiki/Hamiltonian_path_problem
	long long answer_count = 0;
	// vector is more efficient than unordered_set if key is continuous
	vector<bool> visited(size, false);
	vector<int> path;
	for (int i = start; i <= end; i++){
		path.push_back(i);
		visited[i - start] = true;
		answer_count += exaustiveSearch(graph, start, size, path, visited);
		path.pop_back();
		visited[i - start] = false;
	}
	if (answer_count){
		cout << "Totalling " << answer_count << " permutations." << endl;
	}
	else{
		cout << emptyAnswerStr << endl;
	}
}
