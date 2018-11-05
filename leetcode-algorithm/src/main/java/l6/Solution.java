package l6;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public String convert(String s, int numRows) {
        Queue<String> ss = new LinkedList<>(Arrays.asList(s.split("")));
        String[][] stringArr = new String[numRows][s.length()];

        int rowIndex = 0;
        int colIndex = 0;

        if(numRows == 1) return s;

        while (!ss.isEmpty()) {

            // 밑으로 쭉
            while (rowIndex < numRows - 1 && !ss.isEmpty()) {
                stringArr[rowIndex][colIndex] = ss.poll();
                rowIndex++;
            }

            if (ss.isEmpty()) break;

            // 대각선
            while (rowIndex != 0 && !ss.isEmpty()) {
                stringArr[rowIndex][colIndex] = ss.poll();
                rowIndex--;
                colIndex++;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (String[] strings : stringArr) {
            for (String string : strings) {
                if (string == null) {
                    continue;
                }
                sb.append(string);
            }
        }

        return sb.toString();
    }
}