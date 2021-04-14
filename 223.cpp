/*
    ---
    |-|-
    ---|
     ___


     ---
    ---|
    |-|-
    ---
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        int tr[2]={min(C,G),min(D,H)};
        int bl[2]={max(A,E),max(B,F)};
        int intersect=0;
        if (tr[0]>bl[0]&&tr[1]>bl[1])
            intersect=(tr[1]-bl[1])*(tr[0]-bl[0]);
        return (C-A)*(D-B)+(G-E)*(H-F)-intersect;

    }
};

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        /*
            Find IOU
            0,0.  2,2
            3,3   4,4

            00 22
            2-2 40
        */
        vector<int> tr{min(C,G),min(D,H)};
        vector<int> bl{max(A,E),max(B,F)};
        int iou=0;
        if (tr[0]>bl[0]&&tr[1]>bl[1])
            iou=(tr[0]-bl[0])*(tr[1]-bl[1]);
        return (C-A)*(D-B)-iou+(G-E)*(H-F);
    }
};
