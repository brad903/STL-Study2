#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void main()
{
	int arr[] = { 30,50,10,40,30,70,30,90,20,60 };

	vector<int> v(10);

	copy(arr, arr + 10, v.begin()); // 배열을 벡터에 복사

	ostream_iterator<int> out_iter(cout, " : ");

	cout << "********** 변 경 전 **********" << endl;
	copy(v.begin(), v.end(), out_iter);
	cout << endl;

	sort(v.begin(), v.end());

	cout << "********** 변 경 후 **********" << endl;
	copy(v.begin(), v.end(), out_iter);
	cout << endl;

	vector<int>::iterator iter;
	iter = lower_bound(v.begin(), v.end(), 80);
	cout << "\n삽입할 수 있는 정렬된 위치의 가장 첫 번째 위치 : ";
	cout << *iter << "\n\n";

	v.insert(iter, 80);

	cout << "********** 삽 입 후 **********" << endl;
	copy(v.begin(), v.end(), out_iter);
	cout << endl;
}