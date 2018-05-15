#include <vector>
#include <set>
#define max(a,b) (a>b)? a:b
using namespace std;

class FriendScore
{
public:
	int highestScore(vector<string> friends) {
		int F[50][50];
		int n = friends.size();
		set<int> s;
		
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// �� �ະ�� �̾��� ģ�� �߰�
				if (friends[i][j] == 'Y') s.insert(j);
				// �̾��� ģ���� ģ���� �߰�
				for (auto it = s.begin(); it != s.end(); ++it) {
					for (int k = 0; k < n; k++) {
						if (friends[*it][k] == 'Y') s.insert(k);
					}
				}
				// �ڱ� �ڽ� ����
				if (s.end() != s.find(i)) {
					s.erase(s.find(i));
				}
				
			}
			ans = max(ans, s.size());
			s.clear();
		}

		return ans;
		
	}
};

