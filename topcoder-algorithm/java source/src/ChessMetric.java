
public class ChessMetric {
	int[][][] path = new int[100][100][55];
	int[] dx = {1, 1, 1, 0, -1, -1, -1, 0, 1, 2, 2, 1, -1, -2, -2, -1};
	int[] dy = {1, 0, -1, -1, -1, 0, 1, 1, 2, 1, -1, -2, -2, -1, 1, 2}; 
	
	
	public long howMany(int size, int[] start, int[] end, int numMoves) {
		int i,j,x,y;
		int sx=start[0], sy=start[1], ex=end[0], ey=end[1];
		path[sy][sx][0] = 1;
		
		for(i=1; i<=numMoves; i++) {
			for(x=0; x<size; x++) {
				for(y=0; y<size; y++) {
					for(j=0; j<dx.length; j++) {
						int nx = x + dx[j];
						int ny = y + dy[j];
						if(nx<0 || ny<0 || nx>=size || ny>=size) continue;
						
						path[ny][nx][i] += path[y][x][i-1];
					}
				}
			}
		}
		
		return path[ey][ex][numMoves];
	}
	
	public static void main(String[] args) {
		ChessMetric CM = new ChessMetric();
		int[] start = {0,0};
		int[] end = {0,0};
		long x = CM.howMany(3, start, end, 2);
		System.out.println(x);
	}
}
