# SquareNumberInARow
Author: Guohao Zhang (guohaozhang@umbc.edu)
Date: 10/14/2017

Description:
This project provides the SquareNumbersOnPath class and test it.
The said class solves the following problem:
Given a range of integers [start, end], print all possible permutations in which every two consecutive numbers sum up to a perfect square number.

Algorithm:
The algorithm first constructs an undirected graph, in which each node is a number in the range, two nodes are connected if and only if they sum up to a perfect square number.
Then the algorithm do an exaustive depth first search to find all the hamiltonian paths in the graph.
Those paths are the answers and will be printed to the standard output.
Due to the fact that finding hamiltonian paths in a graph is a NP-complete problem, the algorithm can take long time to complete when the input range is large.

Build:
Windows: click the .sln file to use visual studio to open the project
Linux: run make to use the provided makefile to build the project
