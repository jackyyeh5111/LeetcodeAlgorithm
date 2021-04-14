/***** Second Visit *****/
typedef vector<NestedInteger>::iterator VNIT;
class NestedIterator {
public:
    stack<pair<VNIT,VNIT>> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push({nestedList.begin(),nestedList.end()});
    }

    int next() {
        if (!hasNext()) return -1;
        int ret=s.top().first->getInteger();
        auto t=s.top(); s.pop();
        t.first+=1;
        s.push(t);
        return ret;
    }

    bool hasNext() {
        clean();
        if (s.empty()) return false;
        return true;
    }

    void clean() {
        while (!s.empty()) {
            if (s.top().first==s.top().second) {
                s.pop();
                if (!s.empty()) {
                    auto t=s.top(); s.pop();
                    t.first+=1;
                    s.push(t);
                }
            }
            else if (s.top().first->isInteger()) return;
            else s.push({s.top().first->getList().begin(),s.top().first->getList().end()});
        }
    }
};

/***** First Visit *****/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };

 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();

 */

// stack with node value pre saved.
typedef NestedInteger Node;

class NestedIterator {
public:
    stack<Node> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n=nestedList.size();
        for (int i=n-1; i>=0; --i) s.push(nestedList[i]);
    }

    int next() {
        int ret=s.top().getInteger(); s.pop();
        return ret;
    }

    bool hasNext() {
        while (!s.empty()) {
            if (s.top().isInteger()) return true;
            else {
                auto cur=s.top(); s.pop();
                int n=cur.getList().size();
                for (int i=n-1; i>=0; --i) s.push(cur.getList()[i]);
            }
        }
        return false;
    }
};

// stack with real iterator
typedef vector<NestedInteger>::iterator VSIT;
class NestedIterator {
public:
    stack<pair<VSIT,VSIT>> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push({nestedList.begin(),nestedList.end()});
    }

    int next() {
        hasNext();
        auto t=s.top(); s.pop();
        int ret=t.first->getInteger();
        t.first+=1;
        s.push(t);
        return ret;
    }

    bool hasNext() {
        while (!s.empty()) {
            if (s.top().first==s.top().second) {
                s.pop();
                if (!s.empty()) {
                    auto t=s.top(); s.pop();
                    t.first+=1;
                    s.push(t);
                }
            }
            else if (s.top().first->isInteger()) return true;
            else s.push({s.top().first->getList().begin(),s.top().first->getList().end()});
        }
        return false;
    }
};
