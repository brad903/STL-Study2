#include <vector>
using namespace std;

class BadNeighbors
{
    public:
        int maxDonations(vector<int> donations)
        {
            int i;
            int ans = 0;

            int N = donations.size();
            int *dp = new int[N];

            // 0번째부터 시작
            for(i=0; i<N-1; i++){
                dp[i] = donations[i];
                if(i>0) dp[i] = max(dp[i], dp[i-1]);  // 자기를 선택하던지, 바로 앞에 것을 선택하던지
                if(i>1) dp[i] = max(dp[i], dp[i-2]+donations[i]);  // 자기를 선택하던지, 바로 앞앞의 것과 자신을 선택하던지
                ans = max(ans, dp[i]);
            }

            // 1번째부터 시작
            for(i=0; i<N-1; i++){
                dp[i] = donations[i+1];
                if(i>0) dp[i] = max(dp[i], dp[i-1]);
                if(i>1) dp[i] = max(dp[i], dp[i-2]+donations[i]);
                ans = max(ans, dp[i]);
            }

            delete[] dp;
            return ans;
        }
};

int main(){
    // vector<int> donations = {1,2,3,4,5,1,2,3,4,5};
    vector<int> donations = {7,7,7,7,7,7,7};
    BadNeighbors BN;
    int x = BN.maxDonations(donations);
    printf("%d\n", x);

    return 0;
}