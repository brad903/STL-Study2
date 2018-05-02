#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	vector<int> v1;
	vector<int> v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	v2.push_back(3);
	v2.push_back(4);

	vector<int>::iterator iter;

	iter = search(v1.begin(), v1.end(), v2.begin(), v2.end());

	if (iter != v1.end()) {
		cout << "v2는 v1의 서브 집합이며 순서가 같습니다" << endl;
		cout << "첫번째 서브 집합 시작 위치의 index는 "   // 서브 집합의 첫번째 반복자 위치 반환
			<< iter-v1.begin() << "입니다" << endl;

		return 0;
	}
}