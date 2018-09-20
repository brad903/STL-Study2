#include "FriendScore2.h"
#include <iostream>

int main() {
	vector<string> friends = {
		"NNN",
		"NNN",
		"NNN"
	};

	FriendScore2 FS;
	cout << FS.highestScore(friends) << '\n';

	return 0;
}
