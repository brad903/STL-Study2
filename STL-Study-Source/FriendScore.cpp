#include "FriendScore2.h"
#include <iostream>

int main() {
	vector<string> friends = {
		"NYNNN",
		"YNYNN",
		"NYNYN",
		"NNYNY",
		"NNNYN"
	};

	FriendScore2 FS;
	cout << FS.highestScore(friends) << '\n';

	return 0;
}
