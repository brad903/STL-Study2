package l10;

import org.junit.Test;

import static org.junit.Assert.*;
import static org.assertj.core.api.Assertions.assertThat;

public class SolutionTest {
    Solution solution = new Solution();

    @Test
    public void test1() {
        String s = "aa";
        String p = "a";
        assertThat(solution.isMatch(s, p)).isEqualTo(false);
    }

    @Test
    public void test2() {
        String s = "aa";
        String p = "a*";
        assertThat(solution.isMatch(s, p)).isEqualTo(true);
    }

    @Test
    public void test3() {
        String s = "ab";
        String p = ".*";
        assertThat(solution.isMatch(s, p)).isEqualTo(true);
    }

    @Test
    public void test4() {
        String s = "aab";
        String p = "c*a*b";
        assertThat(solution.isMatch(s, p)).isEqualTo(true);
    }

    @Test
    public void test5() {
        String s = "mississippi";
        String p = "mis*is*p*.";
        assertThat(solution.isMatch(s, p)).isEqualTo(false);
    }

    @Test
    public void test6() {
        String s = "miss";
        String p = "....";
        assertThat(solution.isMatch(s, p)).isEqualTo(false);
    }
}