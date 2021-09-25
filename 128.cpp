/***** Sixth Visit *****/
/*
    union/find
    union: T:O(logn)
    find: T:O(logn)

    unordered_map<int,pair<int,bool>>
    k: cur node, v.first is size or parent depends on v.second
        true if root, else false
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,pair<int,bool>> parents;
        int ans=0;
        for (int &num:nums) {
            if (parents.count(num)) continue;
            parents[num]={1,true};
            int t=1;
            if (parents.count(num+1)) t=max(t,myunion(parents,num,num+1));
            if (parents.count(num-1)) t=max(t,myunion(parents,num,num-1));
            ans=max(ans,t);
        }
        return ans;
    }

    int find(unordered_map<int,pair<int,bool>> &parents, int x)
    {
        int root=x;
        while (!parents[root].second)
            root=parents[root].first;
        while (x!=root) {
            int next=parents[x].first;
            parents[x].first=root;
            x=next;
        }
        return root;
    }

    int myunion(unordered_map<int,pair<int,bool>> &parents, int x, int y)
    {
        int rx=find(parents,x), ry=find(parents,y);
        if (rx>ry) swap(rx,ry);
        parents[rx].first+=parents[ry].first;
        parents[ry].first=rx; parents[ry].second=false;
        return parents[rx].first;
    }
};

/***** Fifth Visit *****/
/*
    union/find
    T:O(nlogn)/S:O(1)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // k: current node, v: parent or size? isRoot
        unordered_map<int,pair<int,bool>> parents;
        int ans=0;
        for (int &num:nums) {
            if (parents.count(num)) continue;
            parents[num]={1,true};
            int longest=1;
            if (parents.count(num-1))
                longest=max(longest,myunion(parents,num,num-1));
            if (parents.count(num+1))
                longest=max(longest,myunion(parents,num,num+1));
            ans=max(ans,longest);
        }
        return ans;
    }

    // T:O(logn) in average, best case: T:O(1)
    int find(unordered_map<int,pair<int,bool>> &parents, int x)
    {
        int root=x;
        while (!parents[root].second)
            root=parents[root].first;

        // collapsing
        while (x!=root) {
            int next=parents[x].first;
            parents[x]={root,false};
            x=next;
        }
        return root;
    }

    // T:O(1)
    int myunion(unordered_map<int,pair<int,bool>> &parents, int x, int y)
    {
        // weighting
        int px=find(parents, x), py=find(parents, y);
        if (parents[px].first<parents[py].first) {
            parents[py].first+=parents[px].first;
            parents[px]={py,false};
            return parents[py].first;
        }
        else {
            parents[px].first+=parents[py].first;
            parents[py]={px,false};
            return parents[px].first;
        }
    }
};

/***** Fourth Visit *****/
/*
    union / find
    T:O(1) / T:O(1)
    conduct a parent table with k:cuurrent node, v:<size or parent, isroot>
	Total: T:O(n)/S:O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_map<int,pair<int,bool>> table; //size or parent, isroot
        int ans=0;
        for (int num:nums) {
            if (table.count(num)) continue;
            table[num]={1,true};
            int len=1;
            if (table.count(num-1)) len=max(len,myunion(table,num,num-1));
            if (table.count(num+1)) len=max(len,myunion(table,num,num+1));
            ans=max(ans,len);
        }
        return ans;
    }

    // amortized T:O(1)
    int find(unordered_map<int,pair<int,bool>> &table, int num)
    {
        int root=num;
        while (!table[root].second) {
            root=table[root].first;
        }
        int cur=num;
        while (cur!=root) {
            int next=table[cur].first;
            table[cur]={root,false};
            cur=next;
        }
        return root;
    }

    // amortized T:O(1)
    int myunion(unordered_map<int,pair<int,bool>> &table, int x, int y)
    {
        int rx=find(table, x), ry=find(table, y);
        if (rx<ry) {
            table[rx].first+=table[ry].first;
            table[ry]={rx,false};
            return table[rx].first;
        }
        else {
            table[ry].first+=table[rx].first;
            table[rx]={ry,false};
            return table[ry].first;
        }
    }
};

/***** Third Visit *****/
/*
    sort -> T:O(nlogn) -> T:O(n) bucket sort?
    -----
    use a set to see if the current num is the begin of consecutive sequence.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for (int num:nums) {
            if (s.count(num-1)) continue;
            int t=0;
            while (num+t+1<INT_MAX&&s.count(num+t+1)) t++;
            ans=max(ans,t+1);
        }
        return ans;
    }
};

/***** Second Visit *****/
/*
    Use an unordered_map to record all nums and further reduce searching complexity to T:O(1)
    the answer is at most n, so we have at most 2n numbers to search.
    T:O(n)/S:O(n)
    -----
    2,3,1,7,8,9,10
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n=nums.size(), ans=1;
        if (n<=1) return n;
        unordered_map<int,int> m;
        for (int num:nums) m[num]=-1;
        for (int num:nums) {
            if (m[num]!=-1) continue;
            m[num]=1;
            for (int i=1; i<n; ++i) {
                if (m.count(num+i)==0) break;
                else if (m[num+i]!=-1) {
                    m[num]+=m[num+i];
                    m[num+i]=0;
                    break;
                }
                else {
                    m[num]++;
                    m[num+i]=0;
                }
            }
            ans=max(ans,m[num]);
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        /*
        despite looking like O(n \cdot n)O(n⋅n) complexity, the nested loops
        actually run in O(n + n) = O(n)O(n+n)=O(n) time. All other computations
        occur in constant time, so the overall runtime is linear.

        Just keep in mind use UNION(set) to reduce searching complexity to O(1)
        */
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for (int num:nums) {
            if(s.find(num-1)==s.end()&&num!=INT_MAX) {
                int tmp=1; num++;
                while(num!=INT_MAX&&s.find(num++)!=s.end()) tmp++;
                ans=max(ans,tmp);
            }
        }
        return ans;
    }
};
