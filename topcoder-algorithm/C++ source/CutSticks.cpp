#include <iostream>
#include <vector>
#define max(a,b) (a>b? a:b)
using namespace std;

class CutSticks {
    public:
    double maxKth(vector<int> sticks, int C, int K) {
        double low = 0;
        double high = 1e9;
        int i, j;
        for(int i = 0; i < 100; i++) {
            long long count = 0;
            double mid = (low + high) / 2;
            long long cut = 0;
            for(int j = 0; j < sticks.size(); j++) {
                long long next = (long)(sticks[j] / mid);
                cut += max(0, next - 1);
                count += next;
            }
            count -= max(0, cut - C);
            if(count >= K) low = mid;  // 덜 잘려도 될 때 → 더 큰 수로 나누게 해야함
            else high = mid;  // 더 잘려야 될 때 → 더 작은 수로 나누게 해야함
        }
        return low;  // low, high 둘 중 아무거나 가능
    }
};

    int main() {
        CutSticks cutSticks;
        vector<int> sticks = {76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49};
        int C = 789;
        int K = 459;
        double answer = cutSticks.maxKth(sticks, C, K);
        printf("%f\n", answer);
    }