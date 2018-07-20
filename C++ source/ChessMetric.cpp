#include <vector>
using namespace std;

int path[105][105][55] = {0};
vector<int> dx = {1, 1, 1, 0, -1, -1, -1, 0, 1, 2, 2, 1, -1, -2, -2, -1};
vector<int> dy = {1, 0, -1, -1, -1, 0, 1, 1, 2, 1, -1, -2, -2, -1, 1, 2};

class ChessMetric {
    public: long long howMany(int size, vector<int> start, vector<int> end, int numMoves){
        int x, y, j, i;
        int sx = start[0], sy = start[1], ex = end[0], ey = end[1];
        path[sy][sx][0] = 1;

        for(i=1; i<=numMoves; i++){
            for(x=0; x<size; x++){
                for(y=0; y<size; y++){
                    for(j=0; j<16; j++){
                        int nx = x + dx[j];
                        int ny = y + dy[j];
                        if(nx<0 || ny<0 || nx>=size || ny>=size) continue;

                        path[ny][nx][i] += path[y][x][i-1]; // 1은 여기에 (nx, ny)로 오는 과정
                    }
                }
            }
        }

        return path[ey][ex][numMoves];
    }
};

int main(){
    ChessMetric CM;
    int x = CM.howMany(3, {0,0}, {0,0}, 2);
    printf("%d\n", x);

    return 0;
}