package woowa2;

import org.junit.Test;
import org.slf4j.Logger;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

import static org.assertj.core.api.Assertions.assertThat;
import static org.slf4j.LoggerFactory.getLogger;

public class SolutionTest {
    Solution problem = new Solution();

    private static final Logger log = getLogger(SolutionTest.class);
    public static final String newLine = System.getProperty("line.separator");

    @Test
    public void stringToDateTest() throws ParseException {
        String dateText = "2018-11-10 08:00:05";
        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        Date date = formatter.parse(dateText);
        log.info(date.toString());
    }

    @Test
    public void parseLine() throws ParseException {
        String data = "photo.jpg, seoul, 2018-11-10 08:00:05" + newLine +
        "wow.png, newyork, 2018-10-15 12:15:05" + newLine +
        "a.jpg, seoul, 2018-10-07 12:15:05" + newLine +
        "b.jpg, paris, 2016-10-09 17:15:44" + newLine +
        "c.jpg, paris, 2016-07-13 19:15:22" + newLine +
        "d.jpg, seoul, 2018-06-14 17:18:22" + newLine +
        "e.jpg, seoul, 2018-08-22 13:11:13" + newLine +
        "1111.jpg, paris, 2018-10-14 12:15:05" + newLine +
        "f.jpg, seoul, 2018-09-11 14:02:12" + newLine +
        "g.png, seoul, 2018-05-11 09:02:23" + newLine +
        "h.jpeg, seoul, 2018-02-11 07:02:44" + newLine +
        "i.jpg, seoul, 2017-10-14 12:17:07" + newLine +
        "j.jpg, seoul, 2017-10-14 12:16:02" + newLine +
        "k.jpg, seoul, 2017-10-14 12:15:05" + newLine;

        String answer = problem.solution(data);
        System.out.println(answer);
    }

    @Test
    public void test() {
        String s = "photo.jpg";
        for (String s1 : s.split("\\.")) {
            System.out.println(s1);
        }
    }

}