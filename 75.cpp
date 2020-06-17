/********************* Second Visit ***********************/

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        // sortinig T:O(nlogn), S(1)
        // 2 pass counting sort T:O(n) S:O(COLORS)
        // one pass with 2 pointers

        int l=0, r=nums.size()-1;
        for (int i=0; i<=r; ++i) {
            if (nums[i]==0) swap(nums[i],nums[l++]);
            else if (nums[i]==2) swap(nums[i--],nums[r--]);
        }
    }
};
/*
202110 0,6
002112 0,5
002112 1,5
002112 2,5
001122 2,4
*/


class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        // in-place sorting, quick sort:O(nlogn)
        // T:O(n)
        int x=0,y=nums.size()-1;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]==0) swap(nums[i],nums[x++]);
            if (nums[i]==2&&i<y) swap(nums[i--],nums[y--]);
        }
    }
};

/********************* Quick Sort Implementation ***************************/
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        // T(n)=2T(n/2)+O(n)
        // T:O(nlogn)
        quicksort(nums,0,nums.size()-1);
    }

    void quicksort(vector<int>& nums, int left, int right)
    {
        if (left<right){
            int mid = partition(nums,left,right);
            quicksort(nums,0,mid-1);
            quicksort(nums,mid+1,right);
        }
    }

    int partition(vector<int>& nums, int left, int right)
    {
        int l=left+1; int r=right; int pivot=nums[left];
        while(l<=r){
            while(l<=r&&nums[l]<=pivot) l++;
            while(l<=r&&nums[r]>pivot) r--;
            if (l<r) swap(nums[l],nums[r]);
        }
        swap(nums[left],nums[r]);
        return r;
    }
};
