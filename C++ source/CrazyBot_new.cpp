#include <stdio.h>

bool D[29][29];
double V[29][29];

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
        V[14][14] = 1;

        return dfs(0, 14, 14, -1, -1);
    }

    double dfs(int n, int x, int y, int a, int b){  // a:0→서에서옴, b:0->남에서 옴, -1: 변화없음
        if(D[x][y] != 0) return 0;  // 기존에 방문한 곳이면 Out

        D[x][y] = 1;  // 새로운 곳 방문 표시
        
        if(a == 0){  // 서에서 옴
            V[x][y] = V[x-1][y] * E;
        }else if(a == 1){  // 동에서 옴
            V[x][y] = V[x+1][y] * W;
        }

        if(b == 0){  // 남에서 옴
            V[x][y] = V[x][y-1] * N;
        }else if(b ==1){
            V[x][y] = V[x][y+1] * S;
        }

        printf("%d, %d, %d, %d, %d, %f\n", n, x, y, a, b, V[x][y]);

        if(n == END) return V[x][y];
        
        return dfs(n+1, x-1, y, 1, -1) + dfs(n+1, x+1, y, 0, -1) + dfs(n+1, x, y+1, -1, 0) + dfs(n+1, x, y-1, -1, 1);
    }
};

int main(){
    CrazyBot CB;
    // double x = CB.getProbability(1, 25, 25, 25, 25);
    // double x = CB.getProbability(2, 25, 25, 25, 25);
    double x = CB.getProbability(7, 50, 0, 0, 50);

    printf("%f\n", x);

    return 0;
}