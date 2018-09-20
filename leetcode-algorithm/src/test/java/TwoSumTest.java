import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;

public class TwoSumTest {
    TwoSum solution = new TwoSum();

    @Test
    public void twoSum() {
        int[] nums = {2, 7, 11, 15};
        int[] answer = {1,3};
        int target = 22;

        assertThat(solution.twoSum(nums, target)).isEqualTo(answer);
    }

    @Test
    public void 값_있으면_인덱스_반환() {
        List<Integer> substractedVals = new ArrayList<>();
        substractedVals.add(4);
        substractedVals.add(2);
        int answer = 0;
        int substractedNum = 4;

        assertThat(solution.returnIndex(substractedVals, substractedNum)).isEqualTo(answer);
    }
}