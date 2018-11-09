package l9;

class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) return false;
        String str = String.valueOf(x);
        int len = (str.length() - 1) / 2;

        for (int i = 0; i <= len; i++) {
            if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }
}
