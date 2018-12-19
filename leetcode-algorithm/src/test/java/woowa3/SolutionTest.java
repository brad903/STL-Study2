package woowa3;

import org.junit.Test;

import static org.assertj.core.api.Assertions.assertThat;

public class SolutionTest {
    Solution problem = new Solution();

    @Test
    public void test() {
        int[] A = {60, 80, 40, 40};
        int[] B = {1, 2, 1, 2};
        int M = 3, X = 2, Y = 100;
        assertThat(problem.solution(A, B, M, X, Y)).isEqualTo(7);
    }

    @Test
    public void test2() {
        int[] A = {60, 80, 40, 40};
        int[] B = {1, 1, 1, 1};
        int M = 3, X = 2, Y = 100;
        assertThat(problem.solution(A, B, M, X, Y)).isEqualTo(6);
    }
}