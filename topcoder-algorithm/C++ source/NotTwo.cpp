#include <stdio.h>

int visit[1000][1000];
// there is stones → 1, no stone → -1, not visit → 0
int moveRow[] = {2, -2, 0, 0};
int moveCol[] = {0, 0, 2, -2};

class NotTwo {
    public:
    int maxStones(int col, int row){

        int movedRow, movedCol;
        int result = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){

                if(visit[i][j] == 0) {
                    visit[i][j] = 1;
                    result++; 

                    for(int k=0; k<4; k++){
                        movedRow = i + moveRow[k];
                        movedCol = j + moveCol[k];

                        if(movedRow > -1 && movedRow < row && movedCol > -1 && movedCol < col){
                            if(visit[movedRow][movedCol] != 0) continue;
                            else {
                                visit[movedRow][movedCol] = -1;
                            }
                        }
                     }
                }

            }
        }

        return result;
    }
};

int main(){
    NotTwo notTwo;

    int width = 8;
    int height = 5;

    int result = notTwo.maxStones(width, height);
    printf("%d\n", result);

    // to see stones arragement
    // for(int i=0; i<height; i++){
    //     for(int j=0; j<width; j++){
    //         printf("%d ", visit[i][j]);
    //     }
    //     printf("\n");
    // }
}