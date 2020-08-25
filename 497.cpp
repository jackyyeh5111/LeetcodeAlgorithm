/*
    use a uniform sampler to sample points with a variable to check wheter the rect is sampled.
    NOTE: random should take the area of each rect into consideration.
*/
class Solution {
public:
    vector<vector<int>> rects;
    map<int,int> m;
    int sum=0;
    Solution(vector<vector<int>>& rects) {
        this->rects=rects;
        int idx=0;
        for (auto rect:rects) {
            int area = (rect[2]-rect[0]+1)*(rect[3]-rect[1]+1);
            sum += area;
            m[sum]=idx++;
        }
    }

    vector<int> pick() {
        int k=rand()%sum;
        int idx = m.upper_bound(k)->second;
        int x=rand()%(rects[idx][2]-rects[idx][0]+1)+rects[idx][0];
        int y=rand()%(rects[idx][3]-rects[idx][1]+1)+rects[idx][1];
        return vector<int>{x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
