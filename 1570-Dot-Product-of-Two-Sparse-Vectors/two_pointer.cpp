class SparseVector {
private:
    // unordered_map<int, int> arr; // idx -> val
    vector<pair<int, int>> arr; // idx -> val
public:
    SparseVector(vector<int> &nums) {
        for (int idx = 0; idx < nums.size(); idx++) {
            if (nums.at(idx) != 0)
                arr.emplace_back(idx, nums.at(idx));
        }
    }

    /* 
        [(1, 1), (2, 2), (100, 1)]
        [(100, 2), (10000, 1), ...]
     */
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        // if (this->arr.size() > vec.arr.size())
        //     return vec.dotProduct(*this);
        // two pointers
        int ptr0 = 0, ptr1 = 0;
        int sum = 0;
        while(ptr0 < this->arr.size() && ptr1 < vec.arr.size()) {
            if (this->arr.at(ptr0).first == vec.arr.at(ptr1).first) {
                sum += this->arr.at(ptr0).second * vec.arr.at(ptr1).second;
                ptr0++;
                ptr1++;
            }
            else if (this->arr.at(ptr0).first < vec.arr.at(ptr1).first)
                ptr0++;
            else 
                ptr1++;
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);