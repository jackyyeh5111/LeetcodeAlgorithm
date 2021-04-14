/*
    [[1,3],[2,4]...]
    start<=x<end
    [100,101], [1,2]


*/
class MyCalendar {
public:
    set<pair<int,int>> s; // start, end
    MyCalendar() {

    }

    // T:O(logn), n means the time we call book function
    /*
        1. to check its positiion in our sorted order O(logn)
           [1,2] [2,4]
        2. we are going to insert [start,end) T:O(n)
        T:O(logn+n)/S:O(n) in the worst case

        T:O(n*n) 10^6 if our container vetor
        -----
        for AVL tree
            logn for insertion and search
            logn to find predecessor and successor O(height)

        DS: set

             1
              \
               3
                \
                 null
                 ^
    */
    // T:O(logn)
    bool book(int start, int end)
    {
        pair<int,int> p={start,end};
        auto it=s.lower_bound(p);
        if (it!=s.begin()) {
            auto pred=prev(it);
            // check intersection, [1,2] [1,3] [2,3]
            if (pred->second>p.first) return false;
        }
        if (it!=s.end()) {
            // check intersection
            if (it->first<p.second) return false;
        }
        s.insert(p);
        return true;
    }

    /*
        s: {} [10,20] <-> true
        s: {[10,20], } [15,25] <-> false
        s: {[10,20], } [20,30] <-> true

        [10,20], [10,20], [10,20]
                  ^
    */
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
