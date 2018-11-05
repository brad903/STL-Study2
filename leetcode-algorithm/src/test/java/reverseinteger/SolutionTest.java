package reverseinteger;

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
    public void solution() {
        int input = 123;
        int output = 321;
        assertThat(solution.reverse(input)).isEqualTo(output);
    }
}