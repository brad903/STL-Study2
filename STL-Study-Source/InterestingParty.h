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
				m[first[i]] += 1;     // 해당 주제에 해당하는 하는 사람수 +1
			}
			else { 
				m[first[i]] = 1;      // 최소 1명은 초대하므로 최소값
			}

			if (m.count(second[i])) {
				m[second[i]] += 1;
			}
			else {
				m[second[i]] = 1; 
			}
		}

		int max = 1;  // 리턴값 중 나올 수 있는 최소값
		for (auto x : m) {
			if (max <= x.second) max = x.second;
		}

		return max;

	}
};

// 교재 해법
//class InterestingParty
//{
//public:
//	int bestInvitation(vector<string> first, vector<string> second) {
//
//		map<string, int> dic;
//
//		for (int i = 0; i < first.size(); i++) {  // 중복에 상관없이 모든 후보 일단 넣고 0으로 초기화
//			dic[first[i]] = 0;
//			dic[second[i]] = 0;
//		}
//
//		for (int i = 0; i < first.size(); i++) {  // 각 후보에 대하여 하나씩 증가
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
