#include <vector>
#include <algorithm>
using namespace std;

//class Cryptography
//{
//public:
//	long long encrypt(vector<int> numbers) {
//		
//		vector<long long> s;
//
//		for (int i = 0; i < numbers.size(); i++) {
//			long long val = 1;
//
//			for (int j = 0; j < i; j++) {
//				val *= numbers[j];
//			}
//
//			val *= (numbers[i] + 1);
//
//			for (int k = i+1; k < numbers.size(); k++) {
//				val *= numbers[k];
//			}
//
//			s.push_back(val);
//		}
//
//		long long result=0;
//		vector<long long>::iterator it;
//		
//		for (it = s.begin(); it != s.end(); ++it) {
//			result = max(result, *it);
//		}
//
//		return result;
//	}
//};

// 교재 해법1
//class Cryptography
//{
//public:
//	long long encrypt(vector<int> numbers) {
//
//		long long ans = 0;
//
//		for (int i = 0; i < numbers.size(); i++) {
//			long long temp = 1;
//			for (int j = 0; j < numbers.size(); j++) {
//				if (i == j) {
//					temp *= (numbers[i]+1);
//				}
//				else {
//					temp *= numbers[j];
//				}
//			}
//			ans = max(ans, temp);
//		}
//		return ans;
//	}
//};

class Cryptography
{
public:
	long long encrypt(vector<int> numbers) {

		long long ret = 1;
		sort(numbers.begin(), numbers.end());  // 숫자를 오름차순으로 정렬
		numbers[0]++;  // 제일 작은수 +1 증감
		for (int i = 0; i < numbers.size(); i++) {
			ret *= numbers[i];
		}

		return ret;
	}
};
