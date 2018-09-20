#include <stdio.h>

const int h = 1, w = 1;
int dp[h + 1][w + 1];

int dfs(int nowh, int noww){
    if(nowh > h || noww > w) return 0;
    if(nowh == h && noww == w) return 1;
    if(dp[nowh][noww] != 0) return dp[nowh][noww];
    return dp[nowh][noww] = dfs(nowh+1, noww) + dfs(nowh, noww+1);
}

int main(){
    int x = dfs(0, 0);
    printf("%d\n", x);

    return 0;
}