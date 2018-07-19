#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

void main() {
	vector<int> v1;
	vector<int> v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);

	// 초기값을 0으로 v1, v2의 원소들의 내적
	cout << inner_product(v1.begin(), v1.end(), v2.begin(), 0) << endl;
}