import java.util.ArrayList;

public class HamiltonPath {
	private int cityCount;
	private int[][] visit;
	private final String[] roads;
	ArrayList<ArrayList<Integer>> chunk = new ArrayList<>();

	HamiltonPath(String[] roads) {
		cityCount = roads.length;
		visit = new int[cityCount][cityCount]; // 방문여부 표시
		this.roads = roads;
	}

	public int visitCity(int i) {
		for (int j = 0; j < cityCount; j++) {
			if (visit[j][i] != 0 && roads[j].split("")[i].equals("N")) {
				System.out.println("if문 " + i + ", " + j);
				visit[i][j] = 1; // 방문 표시

				String temp = roads[i].split("")[j];
				if (temp.equals("Y")) {
					System.out.println(j + "호출");
					visitCity(j);
					return j;   
				}
			} else {
				visit[i][j] = 1;
				System.out.println("else문 " + i + ", " + j);
				continue; // continue 넣으니까 다양해졌다 훨
			}
		}
		return -1;
	}

	public int countPaths(String[] roads) {
		for (int i = 0; i < cityCount; i++) {
			ArrayList<Integer> member = new ArrayList<>();
			if (visit[i][0] == 0)
				member.add(i);
			int visitResult = visitCity(i);
			if (visitResult != -1) {
				System.out.println(visitResult + "추가");
				member.add(visitResult);
			}
			if (member.isEmpty() == false)
				chunk.add(member);
		}

		System.out.println(chunk);

		return 0;
	}

	public static void main(String[] args) {
		String[] roads = { "NNNNNY", "NNNNYN", "NNNNYN", "NNNNNN", "NYYNNN", "YNNNNN" };
		HamiltonPath HP = new HamiltonPath(roads);
		HP.countPaths(roads);
	}
}
