/*
    T:O(n)/S:O(n)
    Use linked list could save time while erase elements.
*/
class RecentCounter {
public:
    vector<int> v;
    RecentCounter() {

    }

    int ping(int t) {
        v.push_back(t);
        int i=0,n=v.size();
        while(i<n) {
            if (v[i]<t-3000) i++;
            else break;
        }
        v.erase(v.begin(),v.begin()+i);
        return v.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
