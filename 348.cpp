class TicTacToe {
public:
    int dim_;
    vector<unordered_map<string, int>> histories;
    TicTacToe(int n) {
        dim_ = n;
        histories.resize(2);
    }
    
    
    int move(int row, int col, int player) {
        vector<string> updates{"r"+to_string(row), 
                               "c"+to_string(col)};
        if (row == col)
            updates.push_back("ld");
        if (col == dim_ - row - 1)
            updates.push_back("rd");

        for (const string& str : updates) {
            histories[player-1][str]++;
            if (histories[player-1][str] == this->dim_)
                return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

 /* 
    moves = {
        r0: 2
        c0: 1
        c2: 1
        ld: 1
    }

     left diag: (1, 1), (2, 2) --> (i, i)
    right diag: (0, N-1), (1, N-2) --> (i, N - i - 1)

    N = 3
    O_O
    _OX
    X__
  */