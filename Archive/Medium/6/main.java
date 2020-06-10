class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 0 || numRows == 1 || s.length() == 0 || s.length() == 1)
            return s;
        String result = "";
        for (int i = 0; i < numRows; ++i){
            for ( int j =i; j < s.length(); j += 2*numRows-2){
                result += String.valueOf(s.charAt(j));
                if (i != 0 && i != numRows-1 && (j + 2*numRows-2-2*i)<s.length())
                    result += String.valueOf(s.charAt(j + 2*numRows-2-2*i));
            }
        }
        return result;

    }
}
