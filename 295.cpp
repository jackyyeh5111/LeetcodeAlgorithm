/***** Third Visit *****/
/*
    min/max balance in worst case
    addNum: T:O(nlogn)
    findmedian: T:O(1)
    S:O(n)
    -----
    online sorting in worst case
    addNum: T:O(nlogn)
    findmedian: T:O(1)
    S:O(n)
    -----
    bucket sort
    keep update recorded min/max with predefind k buckets
    T:O(1)
    findmedian: T:O(n)
    S:O(k)
    -----
    tree sorting online
    addNum: T:O(logn)
    findmedian: T:O(logn)
    S:O(n)
*/
class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> minpq;
    priority_queue<int,vector<int>,less<int>> maxpq;
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (maxpq.size()==0) maxpq.push(num);
        else if (num>maxpq.top()) {
            minpq.push(num);
            if(minpq.size()>maxpq.size()) {
                maxpq.push(minpq.top());
                minpq.pop();
            }
        }
        else {
            maxpq.push(num);
            if(maxpq.size()>minpq.size()+1) {
                minpq.push(maxpq.top());
                maxpq.pop();
            }
        }
    }

    double findMedian() {
        int total = minpq.size()+maxpq.size();
        if (total%2) return maxpq.top();
        else return (double)(maxpq.top() + minpq.top())/2.0;
    }
};

/***** Second Visit *****/
/*
    bucket sort
    min
    min+k
    min+2k
    .
    .
    .
    max
    Keep tracking min/max, if min/max alters, update new buckets.
    addNum: amortized T:O(1)
    findMedian: O(logk) by binary search.
    -----
    Use multiset(AVL tree) as online sorting
    addNum: T:O(logn)
    findMedian: O(logn), could reduce to O(1) by maintaining 2 ptr on multiset
    -----
    Balabce 2 heap!
    [left] mid [right]
    [left] mid1 mid2 [right]
    left: max heap
    right: min heap
    addNum: T:O(logn)
    findMedian: O(1)
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {

    }

    void addNum(int num) {
        left.push(num);
        if (left.size()-1>right.size()) {
            int t=left.top(); left.pop();
            right.push(t);
        }
        if ((left.size()!=0&&right.size()!=0)&&left.top()>right.top()) {
            int l=left.top(), r=right.top();
            left.pop(); right.pop();
            left.push(r); right.push(l);
        }
    }

    double findMedian() {
        if (left.size()==right.size()+1)
            return left.top();
        else return (left.top()+right.top())/2.0;
    }
};

/***** First Visit *****/
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
