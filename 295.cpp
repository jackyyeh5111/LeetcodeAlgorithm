/*
    use multiset (AVL tree) to store each num
    S:O(n)
    addNum:T:O(logn)
    findMedian:T:O(1) <--- Actually next op has linear time complexity
    TLE (due to findMedian)
    --------
    we should keep the median with pre defined ptr while adding numbers.
    addNum:T:O(logn)
    findMedian:T:O(1)
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> nums;
    multiset<int>::iterator mid;
    MedianFinder() {

    }

    void addNum(int num) {
        nums.insert(num);
        int n=nums.size();
        if (n==1) mid=nums.begin();
        else if (num < *mid)
            mid=n&1?mid:prev(mid,1);
        else
            mid=n&1?next(mid,1):mid;
    }

    double findMedian() {
        int n=nums.size();
        if (n%2) return *mid;
        else return (*mid+*next(mid,1))/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
