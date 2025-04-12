#include "tspProblem.h"
#include <bitset>
using namespace std;

unsigned int tspProblem::computeMinTourCost(int i, bitset<32> bits){
	unsigned mask = bits.to_ulong();
	if (mask == 0)
		return W->getEdgeCost(i, 0);

	if (D[i][mask] != -1)
		return D[i][mask];
	
	int best_j{ INT_MAX };
	int bestCost{ INT_MAX };

	for (int j = 0; j < mask; j++) {
		int cost = computeMinTourCost(j, bits.reset(j)) + W->getEdgeCost(i, j);
		bits.set(j);
		if (cost < bestCost) {
			bestCost = cost;
			best_j = j;
		}
	}
	D[i][mask] = bestCost;
	P[i][mask] = best_j;
	return bestCost;
}

void tspProblem::solve()
{

}

