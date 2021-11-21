/***** Fifth Visit *****/
/*
    1 2 3 4
    1 2 4 3
    1 3 2 4
    1 3 4 2
    1 4 2 3
    1 4 3 2
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int n=nums.size(), l=-1, r=-1;
        for (int i=0; i<n-1; ++i) {
            if (nums[i]<nums[i+1]) l=i;
        }
        if (l==-1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        for (int i=n-1; i>l; --i) {
            if (nums[i]>nums[l]) {r=i; break;}
        }
        swap(nums[l],nums[r]);
        reverse(nums.begin()+l+1,nums.end());
    }
};

/***** Fourth Visit *****/
/*
    strict increasing order
    [... a b c d e] a<b, b>c>d>e

    1. find last strict increase pair a,b
    2. find the min num larger than a
    3. swap(a,b)
    4. reverse b ~ e
    T:O(n)/S:O(1)
*/

/***** Third Visit *****/
/*
    Constraint: S:O(1)
    1. Find the index which have strict decreasing nums following. This means that nums[index] is done for the perm index starts from nums[idx]
    2. If we cant find this index, it means that the overall nums are all done, then it should be inverse increasing order.
    3. If we find the index, then we are going to next larger number. Find the min num larger than nums[index] which is in the following nums.
    4. swap them, and the following decreasing nums(done) should reverse to increasing (begin).

    Refers: https://www.youtube.com/watch?v=quAS1iydq7U
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),j=-1,k=-1;
        for (int i=n-2; i>=0; i--) {
            if (nums[i]<nums[i+1]) {j=i; break;}
        }
        if (j==-1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        for (int i=n-1;  i>j; --i) {
            if (nums[i]>nums[j]) {k=i; break;}
        }
        swap(nums[j],nums[k]);
        reverse(nums.begin()+j+1,nums.end());
    }
};

/***** Second Visit *****/
/*
    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 1 2
    3 2 1
    brute force:
    permutatation then find next
    T:O(n!)/S:O(1)
    -----
    1 2 3 4 5
    1 2 3 5 4
    1 2 4 3 5
    1 2 4 5 3
    1 2 5 3 4
    1 2 5 4 3
    FAIL, see solution.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int n=nums.size(),k=n-2, l=n-1;
        for (;k>=0; --k) {
            if (nums[k]<nums[k+1]) break;
        }
        if (k==-1) reverse(nums.begin(),nums.end());
        else {
            for (;l>k; --l) {
                if (nums[l]>nums[k]) break;
            }
            swap(nums[l],nums[k]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};

/***** First Visit *****/
class Solution {
public:
    vector<int> ans;
    // Time Limited Expired, T:worst case O(N!)
    void nextPermutation(vector<int>& nums)
    {
        vector<int> target = nums;
        perm(0, nums.size(), nums, target);
        if(ans.size()==0) sort(nums.begin(), nums.end());
        else nums=ans;

    }

    void perm(int start, int end, vector<int>& nums, vector<int>& target)
    {
        if (ans.size()!=0) return;
        if (start+1==end) {
            for (int i=0; i<nums.size(); ++i){
                if (nums[i]>target[i]){
                    cout<<nums[i]<<","<<target[i];
                    ans = nums;
                    return;
                }
                else if(nums[i]<target[i]) break;
            }
        }
        //////////////// sort rest parts for NEXT permutation ///////////////
        vector<int> subvec = vector<int>(nums.begin()+start, nums.end());
        vector<pair<int,int>> subvec_indices;
        for (int i=0; i<subvec.size(); ++i)
            subvec_indices.push_back(make_pair(subvec[i], i));
        sort(subvec_indices.begin(), subvec_indices.end(),
             [](const auto & a, const auto & b) -> bool
             {return a.first <b.first;});
        /////////////////////////////////////////////////////////////////////
        for (auto p:subvec_indices) {
            swap(nums[start], nums[p.second+start]);
            perm(start+1, end, nums, target);
            swap(nums[start], nums[p.second+start]);
        }
    }
};

/*
According to Wikipedia, a man named Narayana Pandita presented the following simple algorithm to solve this problem in the 14th century.

1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
2. Find the largest index l > k such that nums[k] < nums[l].
3. Swap nums[k] and nums[l].
4. Reverse the sub-array nums[k + 1:].
*/
class Solution {
public:
    // T:O(n), S:O(1)
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            }
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
