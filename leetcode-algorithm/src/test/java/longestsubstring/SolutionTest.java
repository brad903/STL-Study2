package longestsubstring;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class SolutionTest {
    Solution solution = new Solution();

    @Test
    public void lengthOfLongestSubstring() {
        System.out.println(solution.lengthOfLongestSubstring("pwwkew"));
    }

    @Test
    public void forTest() {
        for(int i = 0; i < 5; i++) {
            if(i == 4) {
                i = 1;
            }
            System.out.println(i);
        }
    }

    @Test
    public void arrayTest() {
        List<Integer> array = new ArrayList<>();
        array.add(1);
        array.add(2);
        array.add(3);
        array.add(4);
        array.add(5);

        array.remove(0);
        array.remove(0);

        for (Integer integer : array) {
            System.out.println(integer);
        }
    }
}