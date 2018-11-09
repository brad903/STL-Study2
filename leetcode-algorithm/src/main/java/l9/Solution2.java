package l9;

public class Solution2 {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        int temp = x;
        int sum = 0;
        while (temp > 9) {
            sum = (sum * 10) + (temp % 10);
            temp /= 10;
        }
        return sum == (x / 10);
    }
}
