package reverseinteger;

class Solution {
    public int reverse(int x) {
        String xText;
        xText = String.valueOf(x);

        StringBuilder builder = new StringBuilder();

        int leng;
        if(x < 0) leng = 1;
        else leng = 0;

        for (int i = xText.length() - 1; i >= leng; i--) {
            builder.append(xText.charAt(i));
        }

        try {
            if(leng == 1) {
                return Integer.parseInt(builder.toString())*(-1);
            }
            return Integer.parseInt(builder.toString());
        } catch(NumberFormatException e) {
            return 0;
        }

    }
}
