class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int col=coordinates[0]-'a';
        int row=coordinates[1]-'1';
        return (col+row)%2!=0;
    }
};
