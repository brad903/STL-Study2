#include "FriendScore.h"
#include <iostream>

int main() {
	vector<string> friends = {
		"NYY",
		"YNY",
		"YYN"
	};

	FriendScore FS;
	cout << FS.highestScore(friends) << '\n';

	return 0;
}
