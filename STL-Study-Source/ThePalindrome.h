#include <string>
using namespace std;

class ThePalindrome
{
public:
	int find(string s) {
		// 답의 문자 길이를 결정
		for (int i = s.size(); ; i++) {
			bool flag = true;
			for (int j = 0; j < s.size(); j++) {
				// 반대쪽에 문자가 존재하는데 다를 경우 플래그 변경
				if ((i - j - 1) < s.size() && s[j] != s[i - j - 1]) {
					printf("i : %d, j : %d\n", i, j);
					printf("%d\n", i - j - 1);
					flag = false;
					break;
				}
			}
			printf("i증가\n");
			// 조건 모두 만족하면 답 리턴
			if (flag) return i;
		}
	}

};

