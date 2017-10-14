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
	int t = sqrt(num);
	return t*t == num;
}

void SquareNumbersOnPath::printPath(vector<int>& path){
	for (int i = 0; i < path.size(); i++){
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
	for (int i = 0; i < neighbors.size(); i++){
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
	// build the neighbors graph
	// vector is more efficient than unordered_map if key is contineous
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
	int _num_numbers_with_few_neighbors = 0;
	for (int i = 0; i < graph[i].size(); i++){
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
	// vector is more efficient than unordered_set if key is contineous
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
