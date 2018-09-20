#include <vector>
#include <stdio.h>
using namespace std;

class CirclesCountry {
    public:
    char borderJudge(int X, int Y, int R, int a, int b){
        int val = (a - X)*(a - X) + (b - Y)*(b - Y);
        if(val < R*R) return 1;
        else return 0;
    }

    int leastBorders(vector<int> X, vector<int> Y, vector<int> R, int x1, int y1, int x2, int y2){
        int length = X.size();
        vector<char> result1;  // (x1, y1)의 원 소속여부 조사
        vector<char> result2;  // (x2, y2)의 원 소속여부 조사
        int ans = 0;

        for(int i=0; i<length; i++){
            result1.push_back(borderJudge(X[i], Y[i], R[i], x1, y1));
            result2.push_back(borderJudge(X[i], Y[i], R[i], x2, y2));
        }

        for(int j=0; j<length; j++){
            if(result1[j] != result2[j]){
                ans++;
            }
        }

        return ans;
    }
};

int main(){
    // vector<int> X = {0,-6,6}, Y = {0,1,2}, R = {2,2,2};
    // int x1=-5, y1=1, x2=5, y2=1;
    // vector<int> X = {1,-3,2,5,-4,12,12}, Y = {1,-1,2,5,5,1,1}, R = {8,1,2,1,1,1,2};
    // int x1=-5, y1=1, x2=12, y2=1;
    // vector<int> X = {-3,2,2,0,-4,12,12,12}, Y = {-1,2,3,1,5,1,1,1}, R = {1,3,1,7,1,1,2,3};
    // int x1=2, y1=3, x2=13, y2=2;
    vector<int> X = {-107,-38,140,148,-198,172,-179,148,176,153,-56,-187},
    Y = {175,-115,23,-2,-49,-151,-52,42,0,68,109,-174},
    R = {135,42,70,39,89,39,43,150,10,120,16,8};
    int x1=102, y1=16, x2=19, y2=-108;
    
    CirclesCountry CC;
    int temp = CC.leastBorders(X, Y, R, x1, y1, x2, y2);
    printf("%d\n", temp);
    return 0;
}