package l8;

import org.junit.Test;

import static org.junit.Assert.*;
import static org.assertj.core.api.Assertions.assertThat;

public class SolutionTest {
    Solution problem = new Solution();

    @Test
    public void Int_Max() {
        String a = "-91283472332";
        System.out.println(Integer.MIN_VALUE);
    }

    @Test
    public void char값_조사() {
        System.out.println((int)'0');
        System.out.println((int)'1');
        System.out.println((int)'9');
        System.out.println((int)'-');
        System.out.println((int)'+');
        System.out.println((char)44);
    }

    @Test
    public void 공백있을떄_변환() {
        String a = "     -42";
        System.out.println(Integer.parseInt(a.trim()));
    }

    @Test
    public void test1() {
        assertThat(problem.myAtoi("42")).isEqualTo(42);
    }

    @Test
    public void test2() {
        assertThat(problem.myAtoi("   -42")).isEqualTo(-42);
    }

    @Test
    public void test3() {
        assertThat(problem.myAtoi("4193 with words")).isEqualTo(4193);
    }

    @Test
    public void test4() {
        assertThat(problem.myAtoi("words and 987")).isEqualTo(0);
    }

    @Test
    public void test5() {
        assertThat(problem.myAtoi("-91283472332")).isEqualTo(-2147483648);
    }

    @Test
    public void test6() {
        assertThat(problem.myAtoi("+")).isEqualTo(0);
    }

    @Test
    public void test7() {
        assertThat(problem.myAtoi("-")).isEqualTo(0);
    }

    @Test
    public void test8() {
        assertThat(problem.myAtoi("+-2")).isEqualTo(0);
    }

    @Test
    public void test9() {
        assertThat(problem.myAtoi("20000000000000000000")).isEqualTo(2147483647);
    }

    @Test
    public void test10() {
        assertThat(problem.myAtoi(" 0000000000012345678")).isEqualTo(12345678);
    }

    @Test
    public void test11() {
        assertThat(problem.myAtoi("-000000000000001")).isEqualTo(-1);
    }

    @Test
    public void test12() {
        assertThat(problem.myAtoi("010")).isEqualTo(10);
    }
}