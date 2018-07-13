#include <stdio.h>
#include <algorithm>
using namespace std;

int ws[5] = {3, 4, 1, 2, 3};
int ps[5] = {2, 3, 2, 3, 6};
int maxw = 10;

int ret = 0;

void knapsack(int n, int w, int p){
    // printf("호출 : n : %d, w : %d, p : %d\n", n, w, p);
    if(w > maxw) return;  // 무게가 넘어가는 것은 제외
    ret = max(ret, p);
    if(n >= 5) return;  // 다 선택됐으면 종료
    knapsack(n+1, w, p);  // 선택X
    knapsack(n+1, w+ws[n], p+ps[n]);  // 선택O
}

int main(){
    knapsack(0, 0, 0);
    printf("%d\n", ret);
}