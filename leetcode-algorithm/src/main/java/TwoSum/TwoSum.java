package TwoSum;

import java.util.ArrayList;
import java.util.List;

public class TwoSum {

    public int[] twoSum(int[] nums, int target) {
        List<Integer> numVals = new ArrayList<>();
        int index = 0;
        for (int num : nums) {
            int minusNum = target - num;
            if(returnIndex(numVals, minusNum) != -1) {
                int[] answer = new int[2];
                answer[0] = returnIndex(numVals, minusNum);
                answer[1] = index;
                return answer;
            }
            numVals.add(num);
            index++;
        }
        return null;
    }

    public int returnIndex(List<Integer> substractedVals, int minusNum) {
        if (substractedVals.indexOf(minusNum) != -1) {
            return substractedVals.indexOf(minusNum);
        }
        return -1;
    }
}
