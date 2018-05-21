#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> card[4];

class NumberMagicEasy
{
public:
	int theNumber(string answer) {
		card[0] = { 1,2,3,4,5,6,7,8 };
		card[1] = { 1,2,3,4,9,10,11,12 };
		card[2] = { 1,2,5,6,9,10,13,14 };
		card[3] = { 1,3,5,7,9,11,13,15 };

		vector<int> s = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
		vector<int> temp(16);

		for (int i = 0; i < answer.size(); i++) {
			if (answer[i] == 'Y') {
				vector<int> temp2(16);  // 다른 부분을 임시적으로 가지고 있는 변수
				set_difference(s.begin(), s.end(), card[i].begin(), card[i].end(), temp.begin());
				temp2 = temp;
				sort(temp2.begin(), temp2.end());
				temp = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };  // temp 초기화
				set_difference(s.begin(), s.end(), temp2.begin(), temp2.end(), temp.begin());
			}
			else {
				set_difference(s.begin(), s.end(), card[i].begin(), card[i].end(), temp.begin());
			}
			s = temp;
			temp = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			sort(s.begin(), s.end());
		}

		for (auto it = s.begin(); it != s.end(); ++it) {
			if (*it > 0) return *it;
		}
	}
};

