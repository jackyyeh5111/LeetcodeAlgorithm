/*
    round 0, find all rotten oranges as a vector
    Iteratively tracking each rooten oranges and refresh the vector as latest rotten oranges we care.
    if the vector doesn't change, the loop is over. Check the grid to assure if impossible
    T:O(h*w*(h+w))/S:O(h+w)
    * we can save last checking by count rotten oranges in check loop and
      compare to the numbers of all oranges count in first loop.
    ------
    We could save space as modifying grid to which orange we need to focus at
    current loop, but sacrifice time to search all focues oranges.
    T:O(h*w*(h+w))/S:O(h+w)
*/
class Solution {
public:
    int count=0;
    int orangesRotting(vector<vector<int>>& grid)
    {
        vector<vector<int>> rottens;
        int rows=grid.size(), cols=grid[0].size();
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (grid[i][j]==2) rottens.push_back(vector<int>{i,j});
            }
        }

        while(rottens.size()>0) {
            vector<vector<int>> next_rottens;
            for (auto rotten:rottens) {
                int i=rotten[0], j=rotten[1];
                if (i+1<rows&&grid[i+1][j]==1) {
                    grid[i+1][j]=2;
                    next_rottens.push_back(vector<int>{i+1,j});
                }
                if (i-1>=0&&grid[i-1][j]==1) {
                    grid[i-1][j]=2;
                    next_rottens.push_back(vector<int>{i-1,j});
                }
                if (j+1<cols&&grid[i][j+1]==1) {
                    grid[i][j+1]=2;
                    next_rottens.push_back(vector<int>{i,j+1});
                }
                if (j-1>=0&&grid[i][j-1]==1) {
                    grid[i][j-1]=2;
                    next_rottens.push_back(vector<int>{i,j-1});
                }
            }
            if (next_rottens.size()==0) break;
            else {
                rottens=next_rottens;
                count++;
            }
        }

        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (grid[i][j]==1) return -1;
            }
        }
        return count;
    }
};
