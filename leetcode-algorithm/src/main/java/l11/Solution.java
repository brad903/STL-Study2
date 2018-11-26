package l11;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public int maxArea(int[] height) {
        List<Stick> sticks = new ArrayList<>();
        int length = height.length;
        int answer = 0;
        for (int i = 0; i < length; i++) {
            Stick stick = new Stick(i, height[i]);
            sticks.add(stick);
        }

        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                int width = Math.abs(sticks.get(i).index - sticks.get(j).index);
                int level = Math.min(sticks.get(i).height, sticks.get(j).height);
                answer = Math.max(answer, width * level);
            }
        }

        return answer;
    }
}

class Stick {
    int index;
    int height;

    public Stick(int index, int height) {
        this.index = index;
        this.height = height;
    }
}