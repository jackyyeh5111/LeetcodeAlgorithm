/***** Third Visit *****/
/*
    Top K Frequent

    1st pass
    T:O(n)/S:O(n)

    2st pass max heap
    T:O(nlogn)/S:O(n)

    3st pass
    T:O(klogn)
    -----
    1st pass
    T:O(n)/S:O(n)

    2st pass min heap, max size=k
    T:O(nlogk)/S:O(k)

    3rd pass
    T:O(klogk)

    4th pass
    T:O(k)

    better than O(nlogn) where n = nums.size()
*/

typedef pair<int,int> pii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int,int> mp;
        for (int num:nums) mp[num]++;

        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for (auto it=mp.begin(); it!=mp.end(); ++it) {
            pq.push({it->second,it->first});
            if (pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second); pq.pop();
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};

/***** Second Visit *****/
/*
    sort -> T:O(nlogn)/S:O(1) -> bucket sort -> T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<vector<int>> table(n+1,vector<int>{});
        unordered_map<int,int> mp;
        for (int num:nums) mp[num]++;
        for (auto it:mp) {
            table[it.second].push_back(it.first);
        }
        vector<int> ans;
        for (int i=n; i>0; --i) {
            if (ans.size()==k) break;
            if (table[i].size()!=0) {
                for (auto t:table[i]) ans.push_back(t);
            }
        }
        return ans;
    }
};

/***** First Visit *****/
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
