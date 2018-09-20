import java.util.*;
import static java.util.stream.Collectors.*;


public class KakaoNo2 {
	
	public int[] solve(int N, int[] stages) {
		int[] up = new int[N + 2];
		int[] down = new int[N + 2];
		Map<Integer, Double> failRate = new HashMap<Integer, Double>();
		int[] answer = new int[N]; 
		
		for(int i = 0; i < stages.length; i++) {
			for(int j = 1; j <= stages[i]; j++) {
				down[j]++;
				if(j == stages[i]) up[j]++;
			}
		}
		
		for(int i = 1; i <= N; i++) {
			failRate.put(i, (double)up[i]/down[i]);
		}
		
		Map<Integer, Double> sorted = (Map<Integer, Double>) failRate
				.entrySet()
				.stream()
				.sorted(Collections.reverseOrder(Map.Entry.comparingByValue()))
				.collect(toMap(Map.Entry::getKey, Map.Entry::getValue, (e1, e2) -> e2, LinkedHashMap::new));

		Set set = sorted.keySet();
		Iterator iterator = set.iterator();
		int index = 0;
		while(iterator.hasNext()) {
			int key = (int)iterator.next();
			answer[index] = key;
			index++;
		}
	        
        return answer;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		KakaoNo2 kakaoNo2 = new KakaoNo2();
		int[] answer;
		int N = 4;
		int[] stages = {4,4,4,4,4};
		answer = kakaoNo2.solve(N, stages);
		
//		for(int i : answer) {
//			System.out.println(i);
//		}
	}

}
