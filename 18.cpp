class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        /* Use 3SUM
        for (i=start to end)
          do 3sum(i+1, end)
        */
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;

                vector<int> subvector(nums.begin()+i+1, nums.end());
                vector<vector<int>> triplets = threeSum(subvector, target-nums[i]);
                for (auto triplet : triplets) {
                    triplet.push_back(nums[i]);
                    ans.push_back(triplet);
                }

        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int target)
    {
        vector<vector<int>> triplets;
        for (int i=0; i<nums.size(); ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1; int r=nums.size()-1;
            while(l<r) {
                int sum = nums[i]+nums[l]+nums[r];
                if (sum > target) r--;
                else if (sum < target) l++;
                else {
                    triplets.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    l++; r--;
                    while(nums[l]==nums[l-1]&&l<r) l++;
                    while(nums[r]==nums[r+1]&&l<r) r--;
                }
            }
        }
        return triplets;
    }

};

/********************* Expand to N Sum *********************/
// class Solution {
// public:
//     vector<vector<int> > fourSum(vector<int> &num, int target) {
//         vector<vector<int> > res;
//         std::sort(num.begin(),num.end());
//         for (int i = 0; i < num.size(); i++) {
//             int target_3 = target - num[i];
//             for (int j = i + 1; j < num.size(); j++) {
//                 int target_2 = target_3 - num[j];
//                 int front = j + 1;
//                 int back = num.size() - 1;
//                 while(front < back) {
//                     int two_sum = num[front] + num[back];
//                     if (two_sum < target_2) front++;
//                     else if (two_sum > target_2) back--;
//                     else {
//                         vector<int> quadruplet(4, 0);
//                         quadruplet[0] = num[i];
//                         quadruplet[1] = num[j];
//                         quadruplet[2] = num[front];
//                         quadruplet[3] = num[back];
//                         res.push_back(quadruplet);
//                         // Processing the duplicates of number 3
//                         while (front < back && num[front] == quadruplet[2]) ++front;
//                         // Processing the duplicates of number 4
//                         while (front < back && num[back] == quadruplet[3]) --back;
//                     }
//                 }
//                 // Processing the duplicates of number 2
//                 while(j + 1 < num.size() && num[j + 1] == num[j]) ++j;
//             }
//             // Processing the duplicates of number 1
//             while (i + 1 < num.size() && num[i + 1] == num[i]) ++i;
//
//         }
//
//         return res;
//
//     }
// };
