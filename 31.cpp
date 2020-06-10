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
