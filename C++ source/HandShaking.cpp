#include <vector>
using namespace std;

class HandsShaking {
    long C[51];

    public: 
    long long countPerfect(int k){
        int n = k/2;
        C[1]=1, C[2]=2;

        if(n>2){
            for(int i=3; i<=n; i++){
                C[i] += C[i-1]*2;  // 양 옆과 악수했을 경우
                for(int j=1; j<=i-2; j++){  // 양 옆 이외에 그 사이 차례대로 악수
                    C[i] += C[j]*C[i-1-j];
                }
            }
        }

        return C[n];
    }
};

int main(){
    HandsShaking HS;
    printf("%lld\n", HS.countPerfect(10));

    return 0;
}