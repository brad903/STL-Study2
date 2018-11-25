package l10;

class Solution {
    public boolean isMatch(String s, String p) {
        boolean answer= false;
        int currentIndex = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < p.length(); i++) {
            char c = p.charAt(i);
            if(c == '*') {
                // 여러가지 경우의 수 고려
            } else {
                sb.append(s.charAt(currentIndex));
            }
            currentIndex++;
        }
        System.out.println(sb);
        if(sb.equals(s)) answer = true;
        return answer;
    }
}
