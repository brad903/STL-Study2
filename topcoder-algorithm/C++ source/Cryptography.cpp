#include "Cryptography.h"
#include <iostream>
using namespace std;

int main() {
	// �׽�Ʈ ���̽�
	vector<int> numbers = { 1, 3, 2, 1, 1, 3 };
	/*vector<int> numbers = { 1000, 999, 998, 997, 996, 995 };*/

	Cryptography crypto;

	cout << crypto.encrypt(numbers) << '\n';

	return 0;
}
