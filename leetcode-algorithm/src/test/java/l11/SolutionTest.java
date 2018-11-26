package l11;

import org.junit.Test;

import static org.junit.Assert.*;
import static org.assertj.core.api.Assertions.assertThat;

public class SolutionTest {
    Solution solution = new Solution();

    @Test
    public void test1() {
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        assertThat(solution.maxArea(height)).isEqualTo(49);
    }
}