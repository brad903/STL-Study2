#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 요소의 값을 출력하는 함수 정의
void PrintElement(int n)
{
	cout << n << "  ";
}

void main()
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(4);
	v1.push_back(1);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(3);
	v2.push_back(7);
	v2.push_back(9);
	v2.push_back(4);
	v2.push_back(2);

	cout << "전체구간" << endl;
	for_each(v1.begin(), v1.end(), PrintElement); cout << endl;
	for_each(v2.begin(), v2.end(), PrintElement); cout << endl;
	cout << endl;
	for_each(v1.begin() + 2, v1.begin() + 5, PrintElement); cout << endl;
	for_each(v2.begin() + 2, v2.begin() + 5, PrintElement); cout << endl;
	cout << endl;
	if (equal(v1.begin() + 2, v1.begin() + 5, v2.begin() + 2) == true)
		cout << "두 벡터의 일부 구간이 일치" << endl;
	else
		cout << "두 벡터의 일부 구간이 일치하지 않음" << endl;
}