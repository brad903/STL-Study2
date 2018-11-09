package l9;

import org.junit.Test;

import static org.junit.Assert.*;
import static org.assertj.core.api.Assertions.assertThat;

public class SolutionTest {
    Solution2 problem = new Solution2();

    @Test
    public void test1() {
        assertThat(problem.isPalindrome(121)).isEqualTo(true);
    }

    @Test
    public void test2() {
        assertThat(problem.isPalindrome(-121)).isEqualTo(false);
    }

    @Test
    public void test3() {
        assertThat(problem.isPalindrome(1)).isEqualTo(true);
    }
}