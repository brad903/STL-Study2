package woowa2;

import org.slf4j.Logger;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

import static org.slf4j.LoggerFactory.getLogger;

public class Solution {
    private static final Logger log = getLogger(Solution.class);
    public static final String DOT = "\\.";
    public static final String newLine = System.getProperty("line.separator");

    public String solution(String S) throws ParseException {
        List<Data> dataList = new ArrayList<>();
        init(dataList, S);
        Map<String, List<Data>> dataMap = new HashMap<>();

        for (Data data : dataList) {
            if(dataMap.containsKey(data.city)) {
                dataMap.get(data.city).add(data);
            } else {
                List list = new ArrayList();
                list.add(data);
                dataMap.put(data.city, list);
            }
        }

        List<Data> newDataList = new ArrayList<>();
        for (String s : dataMap.keySet()) {
            List<Data> list = dataMap.get(s);
            int num = 1;
            boolean isExceedTen = list.size() >= 10 ? true : false;
            for (Data data : list) {
                if(isExceedTen) data.newName = cityFormat(data.city) + String.format("%02d", num);
                else data.newName = cityFormat(data.city) + num;
                data.newName += ("." + data.type);
                num++;
            }
            newDataList.addAll(list);
        }

        Comparator<Data> compartor = new Comparator<Data>() {
            @Override
            public int compare(Data o1, Data o2) {
                return o1.index - o2.index;
            }
        };

        Collections.sort(newDataList, compartor);

        return dataToString(newDataList);
    }

    private String dataToString(List<Data> newDataList) {
        StringBuilder sb = new StringBuilder();
        int i = 0;
        while(i < newDataList.size() - 1) {
            sb.append(newDataList.get(i).newName + newLine);
            i++;
        }
        sb.append(newDataList.get(i).newName);
        return sb.toString();
    }

    private String cityFormat(String city) {
        return city.substring(0, 1).toUpperCase() + city.substring(1);
    }

    public void init(List<Data> dataMap, String S) throws ParseException {
        String lines[] = S.split("\\r?\\n");

        for (int i = 0; i < lines.length; i++) {
            String[] parsedText = lines[i].split(",");
            String[] splittedName = parsedText[0].trim().split(DOT);

            Data data = new Data(i, splittedName[0], splittedName[1], parsedText[1].trim(), stringToDate(parsedText[2].trim()));
            dataMap.add(data);
        }

        Collections.sort(dataMap);
    }

    private Date stringToDate(String dateText) throws ParseException {
        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        return formatter.parse(dateText);
    }

    class Data implements Comparable<Data> {
        int index;
        String newName;
        String name;
        String type;
        String city;
        Date date;

        public Data(int index, String name, String type, String city, Date date) {
            this.index = index;
            this.name = name;
            this.type = type;
            this.city = city;
            this.date = date;
        }

        public String getName() {
            return name;
        }

        @Override
        public int compareTo(Data o) {
            int filterVal = city.compareTo(o.city);
            if(filterVal == 0) {
                return date.compareTo(o.date);
            }
            return filterVal;
        }

        @Override
        public String toString() {
            return "Data{" +
                    "index=" + index +
                    ", newName='" + newName + '\'' +
                    ", name='" + name + '\'' +
                    ", type='" + type + '\'' +
                    ", city='" + city + '\'' +
                    ", date=" + date +
                    '}';
        }
    }
}
