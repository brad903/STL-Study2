package l11;

public class Solution2 {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxHeight = 0;
        int answer = 0;
        while(left < right) {
            maxHeight = Math.min(height[left], height[right]);
            answer = Math.max(answer, (right - left) * maxHeight);

            if(height[left] == height[right]) {
                left++;
                right--;
            } else if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return answer;
    }
}
