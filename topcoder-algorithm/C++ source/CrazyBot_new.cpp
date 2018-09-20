#include <stdio.h>

bool D[29][29];

class CrazyBot {
    double E,W,S,N;
    int END;

    public:
    double getProbability(int n, int east, int west, int south, int north){
        END = n;
        E = (double)east/100;
        W = (double)west/100;
        S = (double)south/100;
        N = (double)north/100;

        return dfs(0, 14, 14);
    }

    double dfs(int n, int x, int y){  // a:0→서에서옴, b:0->남에서 옴, -1: 변화없음
        if(D[x][y]) return 0;  // 기존에 방문한 곳이면 Out
        if(n == END) {
            return 1;  // 1*W*E... 이렇게 계산됨
        }

        D[x][y] = 1;  // 새로운 곳 방문 표시

        double ret = 0;
        ret += dfs(n+1, x-1, y) * W + dfs(n+1, x+1, y) * E + dfs(n+1, x, y+1) * N + dfs(n+1, x, y-1) * S;

        D[x][y] = 0;  // 기존 지나온 경로 초기화
        
        return ret;
    }
};

int main(){
    CrazyBot CB;
    double x = CB.getProbability(1, 25, 25, 25, 25);
    // double x = CB.getProbability(2, 25, 25, 25, 25);
    // double x = CB.getProbability(7, 50, 0, 0, 50);

    printf("%f\n", x);

    return 0;
}