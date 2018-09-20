#include "CrazyBot.h"
#include <iostream>
using namespace std;

int main() {
	int n = 7;
	int east = 50;
	int west = 0;
	int south = 0;
	int north = 50;

	CrazyBot CB;
	cout << CB.getProbability(n, east, west, south, north) << '\n';

	return 0;
}