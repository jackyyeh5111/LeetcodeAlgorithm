class MedianFinder {
public:
    vector<int> arr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto it = lower_bound(arr.begin(), arr.end(), num);
        arr.insert(it, num);
    }
    
    /* 
        1 2
     */
    double findMedian() {
        int size = arr.size();
        if (size == 0)
            return 0.0;
        else if (size % 2) // odd
            return (double)arr[size / 2];
        else // even
            return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 /* 
    [2, 3, 4]

  */