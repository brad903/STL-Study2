package woowa3;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class Solution {
    public int solution(int[] A, int[] B, int M, int X, int Y) {
        int answer = 0;
        Queue<Passenger> passengers = new LinkedList();
        init(A, B, passengers);

        while(!passengers.isEmpty()) {
            int curWeight = 0;
            int curPassenger = 0;
            Set<Integer> floors = new HashSet<>();
            while(!passengers.isEmpty() && curWeight + passengers.peek().wegiht <= Y && curPassenger + 1 <= X) {
                Passenger enteredPassenger = passengers.poll();
                curWeight += enteredPassenger.wegiht;
                curPassenger++;
                floors.add(enteredPassenger.floor);
            }
            if(!floors.isEmpty()) answer += (floors.size() + 1);
        }
        return answer;
    }

    private void init(int[] a, int[] b, Queue<Passenger> passengers) {
        for (int i = 0; i < a.length; i++) {
            passengers.add(new Passenger(a[i], b[i]));
        }
    }
}

class Passenger {
    int wegiht;
    int floor;

    public Passenger(int wegiht, int floor) {
        this.wegiht = wegiht;
        this.floor = floor;
    }

    @Override
    public String toString() {
        return "Passenger{" +
                "wegiht=" + wegiht +
                ", floor=" + floor +
                '}';
    }
}

