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
//	int space = capacities[t] - bottles[t];  // toId�� ���� ����
//
//	if (bottles[f] <= space) {  // �ű�°� ��� ����
//		bottles[t] += bottles[f];  // toId�� ��� �ű��
//		bottles[f] = 0;  // fromId�� 0���� ����
//	}
//	else {  // �ű�� ���� �Ϻθ� �� ��(toId �� �� �ִ� ��� �����)
//		bottles[t] += space;  // toId �� ä���
//		bottles[f] -= space;  // fromId���� �ű丸ŭ ����
//	}
//}
