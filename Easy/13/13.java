import java.util.*;

class Solution {
    public int romanToInt(String s)
    {
        char[] tokens = s.toCharArray();
        LinkedHashMap<Character, Integer> dictionary = new LinkedHashMap<Character, Integer>();
        dictionary.put('I', 1);
        dictionary.put('V', 5);
        dictionary.put('X', 10);
        dictionary.put('L', 50);
        dictionary.put('C', 100);
        dictionary.put('D', 500);
        dictionary.put('M', 1000);

        int result = 0;
        for (int idx = 0; idx < tokens.length - 1; ++idx){
            if (dictionary.get(tokens[idx]) < dictionary.get(tokens[idx + 1]))
                result -= dictionary.get(tokens[idx]);
            else
                result += dictionary.get(tokens[idx]);
        }
        result += dictionary.get(tokens[tokens.length - 1]);

        return result;
    }
}
