#include "tspProblem.h"
#include <bitset>
using namespace std;

unsigned int tspProblem::computeMinTourCost(int i, bitset<32> bits){
	unsigned long mask = bits.to_ulong();
	if (mask == 0) {
		return W->getEdgeCost(i, 0);
	}
	else if (this->D[i][mask] >= 0){
		return D[i][mask];
	}

	int bestCost = INT_MAX;
	int best_j = -1;
	bool foundAtLeastOneVertex = false;


	for (size_t j = 0; j < this->size; j++) {
		int aCost = W->getEdgeCost(i, j) + computeMinTourCost(j, fullMask & ~(1 << j));
		if (aCost < bestCost) {
			foundAtLeastOneVertex = true;
			bestCost = aCost;
			best_j = j;
		}
	}
	if (foundAtLeastOneVertex) {
		D[best_j][mask] = bestCost;
		P[i][mask] = best_j;
	}
	return bestCost;
}

void tspProblem::solve()
{

}

