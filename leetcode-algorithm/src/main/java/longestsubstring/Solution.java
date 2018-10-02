package longestsubstring;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        char[] cArray = s.toCharArray();
        List<Character> cList = new ArrayList<>();
        int answer = 0;

        for (int i = 0; i < cArray.length; i++) {
            char c = cArray[i];
            if(cList.contains(c)) {
                answer = Math.max(answer, cList.size());
                int index = cList.indexOf(c);
                for(int j = 0; j <= index; j++) {
                    cList.remove(0);
                }
                cList.add(c);
//                i = index;
                continue;
            }
            cList.add(c);

        }
        answer = Math.max(answer, cList.size());

        return answer;
    }
}
