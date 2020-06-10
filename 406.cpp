// Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        // T:O(nlogn), S:O(n)
        sort(people.begin(), people.end(), [](auto &p1, auto &p2){
            if(p1[0]!=p2[0]) return p1[0]>p2[0];
            else return p1[1]<p2[1];
        });

        vector<vector<int>> ans;
        for (auto person : people) {
            ans.insert(ans.begin()+person[1], person);
        }
        return ans;

    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        // T:O(n^2), S:O(n)
        sort(people.begin(), people.end(), [](auto &p1, auto &p2){
            if (p1[0]==p2[0]) return p1[1] < p2[1];
            return p1[0] < p2[0];
        });

        vector<vector<int>> ans(people.size(),vector<int>{-1,-1});
        for (vector<int> person : people) {
            int h = person[0]; int k = person[1];
            int idx=-1; int count=-1;
            while (idx<(int)(ans.size()-1)&&count!=k) {
                idx++;
                if (h<=ans[idx][0]||ans[idx]==vector<int>{-1,-1}) count++;
            }
            ans[idx]=person;
        }
        return ans;

    }
};

// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// [[4,4], [5,0], [5,2], [6,1], [7,0], [7,1]]

// [[5,0], [0,0], [5,2], [6,1], [4,4], [0,0]]
