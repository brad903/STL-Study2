package woowa1;

public class Solution {
    public int solution(String binaryText) {
        int answer = 0;
        int num = binaryToInt(binaryText);

        while(num != 0) {
            if(num % 2 == 0) num /= 2;
            else num -= 1;
            answer++;
        }

        return answer;
    }

    private int binaryToInt(String binaryText) {
        int num = 0;
        int mutiply = 1;
        for(int i = binaryText.length() - 1; i >= 0; i--) {
            int target = binaryText.charAt(i) == '1'? 1 : 0;
            num += target * mutiply;
            mutiply *= 2;
        }
        return num;
    }
}
