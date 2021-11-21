/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
};
*/
/*
    T(n)=4T(n/4)+O(n) -> T:O(nlogn)
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int h=grid.size(), w=grid[0].size();
        return reconstruct(grid,0,0,w,h);
    }

    Node *reconstruct(vector<vector<int>>& grid, int x, int y, int w, int h)
    {

        Node *ret=new Node();
        bool isLeaf=1; int val=-1;
        for (int i=x; i<x+h; ++i) {
            for (int j=y; j<y+w; ++j) {
                if (val==-1) val=grid[i][j];
                else if (grid[i][j]!=val) {isLeaf=0; break;}
            }
        }
        if (isLeaf) {
            ret->val=val;
            ret->isLeaf=isLeaf;
            return ret;
        }
        ret->topLeft=reconstruct(grid,x,y,w/2,h/2);
        ret->topRight=reconstruct(grid,x,y+w/2,w/2,h/2);
        ret->bottomLeft=reconstruct(grid,x+h/2,y,w/2,h/2);
        ret->bottomRight=reconstruct(grid,x+h/2,y+w/2,w/2,h/2);
        return ret;
    }
};
