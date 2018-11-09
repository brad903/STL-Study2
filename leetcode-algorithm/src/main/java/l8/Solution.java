package l8;

class Solution {
    public int myAtoi(String str) {
        if (str.isEmpty() || str.trim().length() == 0) {
            return 0;
        }

        String newStr = str.trim();
        int len = newStr.length();
        int start = 0;
        int sign = 1;
        long sum = 0;
        if (newStr.charAt(0) == '+') {
            sign = 1;
            start++;
        }
        else if (newStr.charAt(0) == '-') {
            sign = -1;
            start++;
        }

        for (int i = start; i < len; i++) {
            if (!Character.isDigit(newStr.charAt(i))) return (int) sum * sign;
            sum = (sum * 10) + (newStr.charAt(i) - '0');
            if (sum * sign > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (sum * sign < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        }

        return (int) sum * sign;
    }
}