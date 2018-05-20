#include "CrazyBot.h"
#include <iostream>
using namespace std;

int main() {
	int n = 2;
	int east = 25;
	int west = 25;
	int south = 25;
	int north = 25;

	CrazyBot CB;
	cout << CB.getProbability(n, east, west, south, north) << '\n';

	return 0;
}