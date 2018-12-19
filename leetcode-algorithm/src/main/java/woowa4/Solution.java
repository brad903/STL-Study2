package woowa4;

public class Solution {
    int solution(int[] A, int X) {
        int N = A.length;
        if (N == 0) {
            return -1;
        }
        int l = 0;
        int r = N - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (A[m] >= X) {  // 고친 부분
                r = m;  // 고친 부분
            } else {
                l = m + 1;  // 고친 부분
            }
        }
        if (A[l] == X) {
            return l;
        }
        return -1;
    }
}
