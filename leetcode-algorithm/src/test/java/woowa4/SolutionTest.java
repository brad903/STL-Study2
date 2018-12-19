package woowa4;

import org.junit.Test;

import static org.junit.Assert.*;
import static org.assertj.core.api.Assertions.assertThat;

public class SolutionTest {
    Solution problem = new Solution();

    @Test
    public void test() {
        int[] A = {1, 4, 10, 15};
        int X = 15;
        assertThat(problem.solution(A, X)).isEqualTo(3);
    }

    @Test
    public void test2() {
        int[] A = {1, 3, 4, 8, 10, 13, 15};
        int X = 13;
        assertThat(problem.solution(A, X)).isEqualTo(5);
    }
}