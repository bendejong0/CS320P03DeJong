#pragma once
#include <bitset>
#include <vector>
#include "graph.h"
using namespace std;

class tspProblem {
private:
	vector<vector<int>> D;
	vector<vector<int>> P;
	Graph* W;
	unsigned int computeMinTourCost(int i, bitset<32> bits);
	size_t size;
	const size_t MAX_BITS = 32;
	unsigned long fullMask;

public:
	// constructor which takes in a pointer
	// to a graph.
	tspProblem(Graph* g) : W(g), size(W.getNumVertices()) {
		fullMask = (1 << size); // 1*2^size, we can do powers
								// quickly via bitshifts.
		D.resize(size, vector<int>(fullMask, -1));
		P.resize(size, vector<int>(fullMask, -1));
	}

	void solve();
};