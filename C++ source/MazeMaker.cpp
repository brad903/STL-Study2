#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;

bool check[50][50];  
int stage[50][50];  // 길이 

class MazeMaker{
    public:
    int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol){
        queue<pair<int, int>> pathList;
        pair<int, int> last;
        check[startRow][startCol] = 1;
        pathList.push(make_pair(startRow, startCol));  
        int size = moveRow.size();
        int length = maze[0].length();

        while(!pathList.empty()){
            pair<int,int> point = pathList.front(); pathList.pop();
            pair<int,int> movedPoint;

            for(int i=0; i<size; i++){
                movedPoint.first = point.first + moveRow[i];
                movedPoint.second = point.second + moveCol[i];

                if(movedPoint.first < 0 || movedPoint.first >= size || movedPoint.second < 0 || movedPoint.second >= length) continue;

                if(maze[movedPoint.first][movedPoint.second] == '.' && check[movedPoint.first][movedPoint.second] == 0){
                    check[movedPoint.first][movedPoint.second] = 1;
                    stage[movedPoint.first][movedPoint.second] = stage[point.first][point.second] + 1;
                    pathList.push(movedPoint);
                }
            }

            if(pathList.empty()){
                last = point;
            }
        }

        // stage[last.first][last.second] != 0 한줄이지만 꼼짝하지 못할 경우!
        if((last.first == 0 || last.first == length-1 || last.first == 0 || last.first == length-1) && stage[last.first][last.second] != 0) {
            return stage[last.first][last.second];
        }else {
            return -1;
        }
    }
};

int main(){
    vector<string> maze= {".......", "X.X.X..", "XXX...X", "....X..", "X....X.", "......."};
    vector<int> moveRow= { 1, 0, -1, 0, -2, 1}, moveCol= {0, -1, 0, 1, 3, 0};
    int startRow = 5, startCol = 0;

    // vector<string> maze= {"...", "...", "..."};
    // vector<int> moveRow= { 1, 0, -1, 0, 1, 1, -1, -1}, moveCol= {0, 1, 0, -1, 1, -1, 1, -1};
    // int startRow = 0, startCol = 1;

    // vector<string> maze= {"X.X", "...", "XXX", "X.X"};
    // vector<int> moveRow= { 1, 0, -1, 0}, moveCol= {0, 1, 0, -1};
    // int startRow = 0, startCol = 1;

    // vector<string> maze= {"......."};
    // vector<int> moveRow= { 1, 0, 1, 0, 1, 0}, moveCol= {0, 1, 0, 1, 0, 1};
    // int startRow = 0, startCol = 0;

    // vector<string> maze= {"..X.X.X.X.X.X."};
    // vector<int> moveRow= { 2, 0, -2, 0}, moveCol= {0, 2, 0, -2};
    // int startRow = 0, startCol = 0;

    MazeMaker MM;
    int result = MM.longestPath(maze, startRow, startCol, moveRow, moveCol);

    printf("%d\n", result);

    for(int i=0; i<maze.size(); i++){
        for(int j=0; j<maze[0].length(); j++){
            printf("%d ", stage[i][j]);
        }
        printf("\n");
    }

    return 0;
}