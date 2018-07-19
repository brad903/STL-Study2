#include <vector>
using namespace std;

class InterestingDigits
{
public:
	vector<int> digits(int base) {
		vector<int> ans;

		for (int n = 2; n < 99; n++) {
			bool flag = true;

			for (int a = 0; a < base; a++) {
				for (int b = 0; b < base; b++) {
					for (int c = 0; c < base; c++) {
						int num = a * base*base + b * base + c;
						if (num % n == 0 && (a + b + c) % n != 0) { // n의 배수인데 합이 n의 배수가 아니면
							flag = false;
							break;
						}
					}
					if (!flag) break;
				}
				if (!flag) break;
			}
			if (flag) ans.push_back(n);
		}

		return ans;
	}
};

