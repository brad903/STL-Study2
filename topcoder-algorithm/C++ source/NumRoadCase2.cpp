#include <stdio.h>

const int h = 5, w = 4;
int dp[h+1][w+1];

void calc(){
    int i, j;
    dp[0][0] = 1;
    for(i = 0; i <= h; i++){
        for(j = 0; j <= w; j++){
            if(i != 0) dp[i][j] += dp[i-1][j];
            if(j != 0) dp[i][j] += dp[i][j-1];
        }
    }
}

int main(){
    calc();
    printf("최종 결과값 : %d\n", dp[h][w]);
}