public class StockHistory {

	public int maximumEarnings(int initialinvestment, int monthlyContribution, String[] stockPrices) {
		int month_length = stockPrices.length;
		int company_list = stockPrices[0].split(" ").length;
		int[][] stock_price = new int[company_list][month_length];
		float[][] stock_rate = new float[company_list][month_length];
		String[] end_price = stockPrices[month_length - 1].split(" ");
		float ans = 0;

		// stock_price 2차원 배열로 정리
		for (int i = 0; i < month_length; i++) {
			for (int j = 0; j < company_list; j++) {
				stock_price[j][i] = Integer.parseInt(stockPrices[i].split(" ")[j]);
				stock_rate[j][i] = Integer.parseInt(end_price[j]) / (float) stock_price[j][i];
			}
		}

		float max_rate = 1;
		int max_month = 0;
		int level = 0;
		boolean flag = true;
		
		// 범위 내에서 가장 큰 수익률인 경우 조사
		while (true) {
			for (int i = 0; i < company_list; i++) {
				for (int j = level; j < month_length-1; j++) {
					if(stock_rate[i][j] > max_rate) {
						max_rate = stock_rate[i][j];
						max_month = j;
						flag = false;
					} 
				} 
			}
			if(flag) break;
			
			// 경우에 따른 ans 추가
			if(level == 0) {
				ans += (initialinvestment + monthlyContribution*max_month) * (max_rate - 1);
			}else {
				ans += monthlyContribution*(max_month-level+1) * (max_rate -1);
			}
			
			// 초기
			level = max_month+1;
			max_rate = 1;
			flag = true;
		}

		return (int)ans;
	}

	public static void main(String[] args) {
		String stockPrices[] = { "40 50 60", "37 48 55", "100 48 50", "105 48 47", "110 50 52", "110 50 52",
				"110 51 54", "109 49 53" };
//		String stockPrices[] = { "10 20 30", "15 24 32"};
//		String stockPrices[] = { "10", "9"};
		StockHistory SH = new StockHistory();
		int x = SH.maximumEarnings(100, 20, stockPrices);
		System.out.println(x);
	} 

}
