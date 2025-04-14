#include "graph.h"
#include "tspProblem.h"
#include <bitset>

ifstream getFile();

int main() {
	Graph* g = new Graph();
	ifstream f = getFile();
	assert(f.is_open());
	g->read(f);
	cout << "g: " << endl;
	g->print();
	cout << endl;
	bitset<32> s;
	tspProblem salesperson(g);
	salesperson.solve();
	delete g;


}

ifstream getFile() {
	cout << "Please input file name: ";
	string s;
	cin >> s;
	ifstream f(s, ios::in);
	return f;
}