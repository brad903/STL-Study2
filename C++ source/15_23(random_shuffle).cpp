#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void main()
{
	vector<int> v(8);

	for (int i = 0; i < v.size(); i++)
		v[i] = i + 1;

	ostream_iterator<int> out_iter(cout, " : ");

	cout << "********** 변 경 전 **********" << endl;
	copy(v.begin(), v.end(), out_iter);
	cout << endl;

	// random_shuffle은 주어진 구간 내 요소들의 위치를 무작위로 배치한다
	random_shuffle(v.begin(), v.end());

	cout << "********** 변 경 후 **********" << endl;
	copy(v.begin(), v.end(), out_iter);
	cout << endl;


}