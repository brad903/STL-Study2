import java.util.*;

public class KakaoNo1 {

	public String[] solve(String[] record) {
		Vector<String> answer_v = new Vector<String>();
		HashMap<String, String> idData = new HashMap<>();
		// 아이디, 별명 값 저장
		for (String data : record) {
			String[] dataInfo = data.split(" ");

			if (dataInfo[0].equals("Leave"))
				continue;

			idData.put(dataInfo[1], dataInfo[2]);
		}

		// answer값 저장
		for (String data : record) {
			String[] dataInfo = data.split(" ");

			if (dataInfo[0].equals("Enter")) {
				String userIn = idData.get(dataInfo[1]) + "님이 들어왔습니다.";
				answer_v.add(userIn);
			} else if (dataInfo[0].equals("Leave")) {
				String userOut = idData.get(dataInfo[1]) + "님이 나갔습니다.";
				answer_v.add(userOut);
			}
		}
		
		String[] answer = new String[answer_v.size()];
		answer_v.toArray(answer);
		
		for(String s : answer) {
			System.out.println(s);
		}
 
		return answer;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		KakaoNo1 kakaoNo1 = new KakaoNo1();
		String[] answer;
		String[] record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo",
				"Change uid4567 Ryan" };
		answer = kakaoNo1.solve(record);
	}

}
