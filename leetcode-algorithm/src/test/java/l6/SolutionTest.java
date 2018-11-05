package l6;

import org.junit.Test;

import java.util.*;

import static org.junit.Assert.*;
import static org.assertj.core.api.Assertions.assertThat;

public class SolutionTest {
    Solution problem = new Solution();

    @Test
    public void 자료구조_체크() {
        // 리스트 형태로 먼저 넣어주고 그 담엔 get() 사용하여 넣을 수 있구나
        // 근데 실수 가능성 크고 불편
        List<List<String>> stringArr = new ArrayList<>();
        List<String> test = new ArrayList<>(Arrays.asList("a", "b"));
        stringArr.add(test);
        stringArr.add(Arrays.asList("c", "d"));
        stringArr.get(0).add("e");
        stringArr.add(Arrays.asList("z"));

        for (List<String> strings : stringArr) {
            for (String string : strings) {
                System.out.print(string + " ");
            }
            System.out.println();
        }
    }

    @Test
    public void 패턴_찾기() {
        // assertThat(stringArr[1][2] == null).isEqualTo(true);
        String s = "PAYPALISHIRING";
        Queue<String> ss = new LinkedList<>(Arrays.asList(s.split("")));
        int numRows = 4;
        String[][] stringArr = new String[numRows][s.length()];

        int rowIndex = 0;
        int colIndex = 0;
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
                rowIndex--; colIndex++;
            }
        }

        // debug용
//        for (String[] strings : stringArr) {
//            for (String string : strings) {
//                if (string == null) {
//                    System.out.print(" ");
//                    continue;
//                }
//                System.out.print(string);
//            }
//            System.out.println();
//        }

        // 제출용
        StringBuilder sb = new StringBuilder();
        for (String[] strings : stringArr) {
            for (String string : strings) {
                if (string == null) {
                    continue;
                }
                sb.append(string);
            }
        }

        assertThat(sb.toString()).isEqualTo("PINALSIGYAHRPI");
    }

    @Test
    public void 테스트1() {
        assertThat(problem.convert("PAYPALISHIRING", 3)).isEqualTo("PAHNAPLSIIGYIR");
    }

    @Test
    public void 테스트2() {
        assertThat(problem.convert("PAYPALISHIRING", 4)).isEqualTo("PINALSIGYAHRPI");
    }
}