#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class FriendScore2
{
public:
	int highestScore(vector<string> friends) {
		int ans = 0;
		int n = friends.size();

		for (int i = 0; i < n; i++) {
			int cnt = 0;

			for (int j = 0; j < n; j++) {
				if (i = j) continue;  // 자기 자신을 가리키는 경우 넘어감

				if (friends[i][j] == 'Y') {  // 직접 친구인 경우 1 증가
					cnt++;
				}
				else {
					for (int k = 0; k < n; k++) {
						if (friends[j][k] == 'Y' && friends[k][i] == 'Y') {
							cnt++;
							//break;
						}
					}
				}
			}

			ans = max(ans, cnt);
		}

		return ans;

	}
};
