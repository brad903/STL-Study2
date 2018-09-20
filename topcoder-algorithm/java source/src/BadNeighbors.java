
public class BadNeighbors {
	public int maxDonations(int[] donations) {
		int i;
		int ans = 0;
		
		int N = donations.length;
		int[] dp = new int[N];
		
		// 0번째부터 시작
		for(i=0; i<N-1; i++) {
			dp[i] = donations[i];
			if(i>0) dp[i] = Math.max(dp[i], dp[i-1]);
			if(i>1) dp[i] = Math.max(dp[i], dp[i-2]+donations[i]);
			ans = Math.max(ans,  dp[i]);
		}
		
		// 1번부터 시작
		for(i=0; i<N-1; i++) {
			dp[i] = donations[i+1];
			if(i>0) dp[i] = Math.max(dp[i], dp[i-1]);
			if(i>1) dp[i] = Math.max(dp[i], dp[i-2]+donations[i]);
			ans = Math.max(ans,  dp[i]);
		}
		
		return ans;
	}
	
	public static void main(String[] args) {
		int[] donations = {1,2,3,4,5,1,2,3,4,5};
		BadNeighbors BN = new BadNeighbors();
		int x = BN.maxDonations(donations);
		System.out.println(x);
	}
}
