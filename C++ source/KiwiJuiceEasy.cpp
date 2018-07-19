#include "KiwiJuiceEasy.h"
#include <iostream>
using namespace std;

int main() {
	KiwiJuiceEasy kiwi;

	vector<int> capacities = { 14,35,86,58,25,62 };
	vector<int> bottles = { 6,34,27,38,9,60 };
	vector<int> fromId = { 1,2,4,5,3,3,1,0 };
	vector<int> toId = { 0,1,2,4,2,5,3,1 };
	vector<int> Returns;

	Returns = kiwi.thePouring(capacities, bottles, fromId, toId);

	for (int i = 0; i<Returns.size(); i++) {
		cout << Returns[i] << ' ';
	}
	cout << '\n';

	return 0;
}