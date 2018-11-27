package l11;

import l10.Solution2;
import org.junit.Test;

import static org.junit.Assert.*;
import static org.assertj.core.api.Assertions.assertThat;

public class SolutionTest {
    Solution solution = new Solution();
    Solution2 solution2 = new Solution2();

    @Test
    public void test1() {
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        assertThat(solution.maxArea(height)).isEqualTo(49);
    }

    @Test
    public void test2() {
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        assertThat(solution2.maxArea(height)).isEqualTo(49);
    }
}