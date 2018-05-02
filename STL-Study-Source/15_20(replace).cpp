#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void main() {
	int arr[] = { 3,5,1,4,3,7,3,9,2,6 };

	vector<int> v(10);

	copy(arr, arr + 10, v.begin()); // 배열을 벡터로 복사

	ostream_iterator<int> out_iter(cout, " : ");

	cout << "********** 변 경 전 **********" << endl;
	copy(v.begin(), v.end(), out_iter);
	cout << endl;

	// v.begin()~v.end()까지 값 3를 모두 100으로 갱신한다
	// replace(시작, 끝, 바꾸고 싶은 값, 바꾸려는 값);
	replace(v.begin(), v.end(), 3, 100); 

	cout << "********** 변 경 후 **********" << endl;
	copy(v.begin(), v.end(), out_iter);
	cout << endl;
}