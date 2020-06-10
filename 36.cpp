class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        // O(N^2) with brute force
        // check row/column/subblock
        bool rows[9][9]={0},cols[9][9]={0},blocks[9][9]={0};
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                char entry = board[i][j];
                if (entry=='.') continue;
                int num = entry-'1';
                int row = i; int col = j;
                int block = i/3*3+j/3;
                if(rows[row][num]||cols[col][num]||blocks[block][num]) return false;
                rows[row][num]=cols[col][num]=blocks[block][num]=true;
            }
        }
        return true;
    }
};
