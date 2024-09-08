/* 
    brute force!
    
    variables:
        1. cur_row 
        2. cur_col
    sentence = ["a", "bcd", "e"]
    rows = 3, cols = 6
 */
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        /* 
            cur_row = 0
            cur_col = 6
            word_ptr = 1
         */
        int cur_row = 0, cur_col = 0;
        int word_ptr = 0;
        while(cur_row < rows) {
            int word_len = sentence[word_ptr % sentence.size()].size();
            if (cur_col + word_len > cols) {
                cur_row++;
                cur_col = 0;
            }
            else {
                cur_col += (word_len + 1); // followed by a space in a line
                word_ptr++;
            }
        }
        return word_ptr / sentence.size();
    }
};
