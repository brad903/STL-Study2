#include "InterestingParty.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
	// 테스트 케이스1
	/*vector<string> first = { "snakes", "programming", "cobra", "monty" };
	vector<string> second = { "python", "python", "anaconda", "python" };*/

	// 테스트 케이스2
	/*vector<string> first = { "varety", "diversity", "loquacity", "courtesy" };
	vector<string> second = { "talking", "speaking", "discussion", "meeting" };*/

	// 테스트 케이스3
	vector<string> first = { "fishing", "gardening", "swimming", "fishing" };
	vector<string> second = { "hunting", "fishing", "fishing", "biting" };

	InterestingParty invitation;
	int result = invitation.bestInvitation(first, second);

	cout << result << '\n';

	return 0;
}
