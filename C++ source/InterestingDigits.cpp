#include "InterestingDigits.h"
#include <iostream>
using namespace std;

int main() {
	int base = 10;
	InterestingDigits ID;
	auto x = ID.digits(base);
	for(auto i = x.begin(); i != x.end(); ++i){
		cout << *i << ' ';
	}
	cout << '\n';

	return 0;
}