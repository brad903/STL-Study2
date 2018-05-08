#include <vector>
#include <algorithm>

using namespace std;

class KiwiJuiceEasy
{
public:
	vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId)
	{
		for (int i = 0; i < fromId.size(); i++) {
			int sum = bottles[fromId[i]] + bottles[toId[i]];

			bottles[toId[i]] = min(capacities[toId[i]], sum);
			bottles[fromId[i]] = sum - bottles[toId[i]];
		}
		return bottles;
	}
};

//for (int i = 0; i < fromId.size(); i++) {
//	int f = fromId[i];
//	int t = toId[i];
//	int space = capacities[t] - bottles[t];  // toId에 남은 공간
//
//	if (bottles[f] <= space) {  // 옮기는게 모두 들어갈때
//		bottles[t] += bottles[f];  // toId로 모두 옮기고
//		bottles[f] = 0;  // fromId는 0으로 세팅
//	}
//	else {  // 옮기는 것의 일부만 들어갈 때(toId 꽉 차 있는 경우 고려됨)
//		bottles[t] += space;  // toId 꽉 채우고
//		bottles[f] -= space;  // fromId에서 옮긴만큼 빼줌
//	}
//}
