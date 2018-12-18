package woowa1;

import org.junit.Test;

import static org.junit.Assert.*;
import static org.assertj.core.api.Assertions.assertThat;

public class SolutionTest {
    Solution problem = new Solution();

    @Test
    public void binary() {
        String binaryText = "011100";
        int num = 0;
        int mutiply = 1;
        for(int i = binaryText.length() - 1; i >= 0; i--) {
            int target = binaryText.charAt(i) == '1'? 1 : 0;
            num += target * mutiply;
            mutiply *= 2;
        }

        assertThat(num).isEqualTo(28);
    }

    @Test
    public void test() {
        assertThat(problem.solution("011100")).isEqualTo(7);
    }

    @Test
    public void test2() {
        assertThat(problem.solution("010000")).isEqualTo(5);  // 16 - 8 - 4 - 2 - 1 - 0
    }
}