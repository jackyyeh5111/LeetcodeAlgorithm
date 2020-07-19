/************************** T:O(nlogk), S:O(n) **************************/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        /*
            hashmap to calculate frequency, T:O(n), S:O(n)
            find kth num T:O(n)
            3 pass
            1 2 3 4 5 6 7, 3th
        */
        unordered_map<int,int> m;
        for (int num:nums) m[num]++;

        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for (auto it=m.begin(); it!=m.end(); ++it) {
            pq.push(make_pair(it->second,it->first));
            if (pq.size()>(m.size()-k)) {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};

/************************** T:O(n), S:O(n) **************************/
// WORST CASE: T:O(N^2)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        /*
            hashmap to calculate frequency, T:O(n), S:O(n)
            find kth num T:O(n)
            3 pass
            1 2 3 4 5 6 7, 3th
        */
        unordered_map<int,int> m;
        for (int num:nums) m[num]++;
        vector<int> v;
        for (auto it=m.begin(); it!=m.end(); ++it)
            v.push_back(it->second);
        int kth = selectk(v,0,v.size()-1,v.size()-k);
        cout<<kth<<endl;
        vector<int> ans;
        for (auto it=m.begin(); it!=m.end(); ++it) {
            if (it->second >= kth) ans.push_back(it->first);
        }
        return ans;
    }

    int partition(vector<int> &v, int left, int right)
    {
        int pivot=v[left];
        int i=left+1, j=right;
        while(i<=j) {
            while(i<=j&&v[i]<=pivot) i++;
            while(i<=j&&v[j]>pivot) j--;
            if (i<j) swap(v[i],v[j]);
        }
        swap(v[left],v[j]);
        return j;
    }

    int selectk(vector<int> &v, int left, int right, int k)
    {
        int mid = partition(v,left,right);
        if (mid==k) return v[mid];
        else if (mid>k) return selectk(v,left,mid-1,k);
        else return selectk(v,mid+1,right,k);
    }
};
