#include <string>
#include <vector>
#define max(a,b) (a>b)? a:b
using namespace std;

class FriendScore2
{
public:
	int highestScore(vector<string> friends) {
		int ans = 0;
		int n = friends[0].length();

		for (int i = 0; i < n; i++) {
			int cnt = 0;

			for (int j = 0; j < n; j++) {
				if (i = j) continue;  // �ڱ� �ڽ��� ����Ű�� ��� �Ѿ

				if (friends[i][j] == 'Y') {  // ���� ģ���� ��� 1 ����
					cnt++;
				}
				else {
					for (int k = 0; k < n; k++) {
						if (friends[i][k] == 'Y' && friends[k][j] == 'Y') {
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
