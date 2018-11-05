package no5;

import org.junit.Before;
import org.junit.Test;

import static org.assertj.core.api.Assertions.assertThat;

public class SolutionTest {
    Solution solution;

    @Before
    public void setUp() throws Exception {
        solution = new Solution();
    }

    @Test
    public void longestPalindrome() {
        assertThat(solution.longestPalindrome("cbbd")). isEqualTo("bb");
        assertThat(solution.longestPalindrome("babad")). isEqualTo("bab");
        assertThat(solution.longestPalindrome("")). isEqualTo("");
    }

    @Test
    public void expandAroundCenter() {
        assertThat(solution.expandAroundCenter("babad", 0, 0)).isEqualTo(1);
    }
}