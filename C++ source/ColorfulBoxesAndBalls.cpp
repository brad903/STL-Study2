#include <algorithm>
using namespace std;

    class ColorfulBoxesAndBalls {
        public:
        int getMaximum(int numRed,int numBlue,int onlyRed, int onlyBlue, int bothColors){
            int result = 0;
            int numBoth = min(numRed, numBlue);
            
            // 경우의 수 1: onlyRed, onlyBlue만 있는 경우
            result = onlyRed*numRed + onlyBlue*numBlue;

            // 경우의 수 2: 혼합이 존재하는 경우
            for(int i=1; i<=numBoth; i++){
                int temp = onlyRed*(numRed-i) + onlyBlue*(numBlue-i) + bothColors*2*i;  // 하나 바꿀때마다 bothColor 개수가 2배씩 늘어남
                result = max(temp, result);
            }

            return result;
        }
    };

int main(){
    ColorfulBoxesAndBalls CBB;
    // int x = CBB.getMaximum(2, 3, 100, 400, 200);
    // int x = CBB.getMaximum(2, 3, 100, 400, 300);
    // int x = CBB.getMaximum(5, 5, 464, 464, 464);
    // int x = CBB.getMaximum(1, 4, 20, -30, -10);
    int x = CBB.getMaximum(9, 1, -1, -10, 4);  // 이 경우 맞지않음
    printf("정답 : %d\n", x);
    return 0;
}