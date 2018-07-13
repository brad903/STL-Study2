#include <stdio.h>
#include <algorithm>
using namespace std;

int ws[5] = {3, 4, 1, 2, 3};
int ps[5] = {2, 3, 2, 3, 6};
int maxw = 10;
int dp[6][11];

int knapsack(int n, int w){
    if(w > maxw) return -100;  // 무게 초과된 것이 다음에 선택되는 경우도 있으므로 충분히 작은 수로 리턴값 줘서 나중에 max에서 선택 안되게 함
    if(n >= 5) return 0;
    if(dp[n][w] > 0) return dp[n][w];
    return dp[n][w] = max(knapsack(n+1, w), (knapsack(n+1, w+ws[n]) + ps[n]));
}

int main(){
    int x = knapsack(0, 0);
    printf("%d\n", x);
}