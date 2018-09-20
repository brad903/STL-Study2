#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class InterestingParty
{
public:
	int bestInvitation(vector<string> first, vector<string> second) {
		
		map<string, int> m;

		for (int i = 0; i < first.size(); i++) {
			if (m.count(first[i])) {
				m[first[i]] += 1;     // �ش� ������ �ش��ϴ� �ϴ� ����� +1
			}
			else { 
				m[first[i]] = 1;      // �ּ� 1���� �ʴ��ϹǷ� �ּҰ�
			}

			if (m.count(second[i])) {
				m[second[i]] += 1;
			}
			else {
				m[second[i]] = 1; 
			}
		}

		int max = 1;  // ���ϰ� �� ���� �� �ִ� �ּҰ�
		for (auto x : m) {
			if (max <= x.second) max = x.second;
		}

		return max;

	}
};

// ���� �ع�
//class InterestingParty
//{
//public:
//	int bestInvitation(vector<string> first, vector<string> second) {
//
//		map<string, int> dic;
//
//		for (int i = 0; i < first.size(); i++) {  // �ߺ��� ������� ��� �ĺ� �ϴ� �ְ� 0���� �ʱ�ȭ
//			dic[first[i]] = 0;
//			dic[second[i]] = 0;
//		}
//
//		for (int i = 0; i < first.size(); i++) {  // �� �ĺ��� ���Ͽ� �ϳ��� ����
//			dic[first[i]]++;
//			dic[second[i]]++;
//		}
//
//		int ans = 0;
//		map<string, int>::iterator it;
//
//		for (it = dic.begin(); it != dic.end(); ++it) {
//			ans = max(ans, it->second);
//		}
//
//		return ans;
//	}
//};
