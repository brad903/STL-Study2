package l8;

class Solution {
    public int myAtoi(String str) {
        String spaceRemoved = str.trim();
        int startIndex = 0;
        int lastIndex = 0;
        for (char c : spaceRemoved.toCharArray()) {
            if ((c < '0' || c > '9') && (c != '+') && (c != '-')) break;
            lastIndex++;
        }

        if (spaceRemoved.startsWith("-0") || spaceRemoved.startsWith("+0") || spaceRemoved.startsWith("0")) {
            boolean plus = false, minus = false;
            for (char c : spaceRemoved.toCharArray()) {
                if(c == '0' || c == '+' || c == '-') startIndex++;
                else break;
            }
        }

        if (lastIndex - startIndex > 12) lastIndex = startIndex + 12;
        String answer = spaceRemoved.substring(startIndex, lastIndex);
        try {
            long longer = Long.parseLong(answer);
            if (longer < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            } else if (longer > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            } else if(spaceRemoved.charAt(0) == '-' && startIndex != 0) {
                return Integer.parseInt(answer) * (-1);
            }
            return Integer.parseInt(answer);
        } catch (NumberFormatException e) {
            return 0;
        }
    }
}
