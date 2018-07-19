#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

void main()
{
	int arr[] = { 3,5,1,4,8,7,0,9,2,6 };

	vector<int> v(10);

	copy(arr, arr + 10, v.begin());

	cout << "** 요소들을 구분자 없이 표준 출력 장치로 출력 **" << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout));
	cout << "\n\n";

	cout << "** 요소들을 구분자(:)와 함께 표준 출력 장치로 출력 **" << endl;

	// 출력할 때 ostream_iterator 반복자 통해 구분자 사용가능
	ostream_iterator<int> out_iter(cout, " : ");   
	copy(v.begin(), v.end(), out_iter);
	cout << "\n\n";

	cout << "**** 역방향 반복자로 요소들을 역으로 출력 ****" << endl;
	copy(v.rbegin(), v.rend(), out_iter);
	cout << "\n\n";
}