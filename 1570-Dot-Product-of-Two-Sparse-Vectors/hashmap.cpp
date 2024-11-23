class SparseVector {
private:
    unordered_map<int, int> arr; // idx -> val
public:
    SparseVector(vector<int> &nums) {
        for (int idx = 0; idx < nums.size(); idx++) {
            if (nums.at(idx) != 0)
                arr[idx] = nums[idx];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        if (this->arr.size() > vec.arr.size())
            return vec.dotProduct(*this);
        int sum = 0;
        for (const auto &[idx, val] : this->arr) {
            if (vec.arr.count(idx))
                sum += vec.arr.at(idx) * this->arr.at(idx);
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);