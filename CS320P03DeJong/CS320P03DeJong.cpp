#include "graph.h"
#include "tspProblem.h"
#include <bitset>

ifstream getFile();

int main() {
	Graph* g = new Graph();
	ifstream f = getFile();
	assert(f.is_open());
	g->read(f);
	bitset<32> s;
	tspProblem(g);



}

ifstream getFile() {
	cout << "Please input file name: ";
	string s;
	cin >> s;
	ifstream f(s, ios::in);
	return f;
}