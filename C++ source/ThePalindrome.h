#include <string>
using namespace std;

class ThePalindrome
{
public:
	int find(string s) {
		// ���� ���� ���̸� ����
		for (int i = s.size(); ; i++) {
			bool flag = true;
			for (int j = 0; j < s.size(); j++) {
				// �ݴ��ʿ� ���ڰ� �����ϴµ� �ٸ� ��� �÷��� ����
				if ((i - j - 1) < s.size() && s[j] != s[i - j - 1]) {
					printf("i : %d, j : %d\n", i, j);
					printf("%d\n", i - j - 1);
					flag = false;
					break;
				}
			}
			printf("i����\n");
			// ���� ��� �����ϸ� �� ����
			if (flag) return i;
		}
	}

};

