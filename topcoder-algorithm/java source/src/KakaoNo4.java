public class KakaoNo4 {

    public int solve(int[] food_times, long k) { 
    	int curFood = 0;
    	
    	for(int i = 0; i < k; i++) {

    		// 현재 음식의 남은게 없을 때 
    		if(food_times[curFood] == 0) {
    			int lastPoint = curFood;
    			int response = findNextFood(food_times, curFood + 1, lastPoint);
    			if(response == -1) {
    				return -1;
    			} else if(response >= 0) {
    				curFood = response;
    			}
    		}
    		
    		if(food_times[curFood] == 0) return -1;
    		food_times[curFood]--;
    			
    		curFood++;
    		if(curFood >= food_times.length) curFood = 0;
    	}
    	
        int answer = curFood + 1;
        return answer;
    }
    
    public int findNextFood(int[] food_times, int curFood, int lastPoint) {
    	if(curFood >= food_times.length) curFood = 0;
    	if(curFood == lastPoint) return -1;
    	
    	if(food_times[curFood] != 0) {
    		return curFood;
    	} else {
    		findNextFood(food_times, curFood + 1, lastPoint);
    		return curFood + 1;
    	} 
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		KakaoNo4 kakaoNo4 = new KakaoNo4();
		int[] food_times = {1, 0, 0};
		long k = 2;
		int answer = kakaoNo4.solve(food_times, k);
		System.out.println(answer);
	}

}
