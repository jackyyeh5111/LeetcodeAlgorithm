/*
    brute force
    enumerate all pairs and find max
    T:O(n^2)/S:O(1)
    -----
    Array
    1. 2 ptr solution
    2. moving window
    3. binary search
    4.
        DP
        Greedy
        Divide&Conquer
    -----
    Try 2 ptr solution, say. a,b. which denote 2 nums with largest xor.
    FAIL
    -----
    Greedy bit manipulation
    Use a^b=c <-> a^c=b, and iteratively check left k bits.
    T:O(n)/S:O(n)
    -----
    Use TRIE, treat it as string and do char comparison
    T:O(n)/S:O(n)
*/

/***** Greedy bit manipulation *****/
class Solution {
public:
    int findMaximumXOR(vector<int>& nums)
    {
        int max_result=0,mask=0;
        for (int i=31;i>=0; --i) {
            mask=mask|1<<i;
            unordered_set<int> s;
            for (int num:nums) s.insert(num&mask);
            int greedy=max_result|1<<i;
            for (auto it=s.begin();it!=s.end();++it){
                if(s.count((*it)^greedy)) {
                    max_result=greedy;
                    break;
                }
            }
        }
        return max_result;
    }
};

/***** TRIE Solution *****/
class Solution {
public:
    class TrieNode {
    public:
        TrieNode* next[2];
        TrieNode()
        {
            next[0]=0; next[1]=0;
        }
    };

    TrieNode* buildTree(vector<int>& nums)
    {
        TrieNode* root=new TrieNode();
        for (int num:nums) {
            TrieNode *cur=root;
           for (int j=31; j>=0; --j) {
               int index=(num>>j)&1;
               if (!cur->next[index])
                   cur->next[index]=new TrieNode();
               cur=cur->next[index];
           }
        }
        return root;
    }

    int help(TrieNode *node, int num)
    {
        int ret=0;
        for (int i=31; i>=0; --i) {
            int index=!((num>>i)&1);
            if (node->next[index]) {
                ret=(ret<<1)+1;
                node=node->next[index];
            }
            else {
                ret=ret<<1;
                node=node->next[1-index];
            }
        }
        return ret;
    }

    int findMaximumXOR(vector<int>& nums)
    {
        int ans=0;
        TrieNode *root=buildTree(nums);
        for(int num:nums){
            ans=max(ans,help(root,num));
        }
        return ans;
    }
};
