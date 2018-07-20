
public class HandsShaking {
	public long countPerfect(int n) {
		int[] C = new int[n/2+1];
		C[0] = 1; 
		
		for(int i=1; i<=n/2; i++) {
			C[i] = 0;
			for(int j=0; j<i; j++) {
				C[i] += C[j]*C[i-1-j];
			}
		}
		
		return C[n/2];
	}
	
	public static void main(String[] args) {
		HandsShaking HS = new HandsShaking();
		System.out.println(HS.countPerfect(10));
	}
}
