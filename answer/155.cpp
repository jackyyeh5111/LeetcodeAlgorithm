/***** Second Visit *****/
class MinStack {
public:
    /** initialize your data structure here. */
    vector<pair<int,int>> v;
    MinStack() {

    }

    void push(int x) {
        if (v.empty()) v.push_back(make_pair(x,x));
        else v.push_back(make_pair(x,min(x,v.back().second)));
    }

    void pop() {
        v.pop_back();
    }

    int top() {
        return v.back().first;
    }

    int getMin() {
       return v.back().second;
    }
};

/***** First Visit *****/
/*********************** vector<int>  with T:O(1) ***********************/
/*
    push(x):
    Each time we have a min input, record LAST min right next to the val, and
    update min.
    pop():
    Each time we pop out the min val, we can get the next min in the previous
    val.
    All operations are T:O(1)
*/
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> vec;
    int min=INT_MAX;
    MinStack() {

    }

    void push(int x) {
        if (x<=min){
            vec.push_back(min);
            min=x;
        }
        vec.push_back(x);
    }

    void pop() {
        int back=vec.back(); vec.pop_back();
        if (back==min){
            min=vec.back();
            vec.pop_back();
        }
    }

    int top() {
        return vec.back();
    }

    int getMin() {
        return min;
    }
};

/**************** vector<pair<int,int>>  with T:O(1) ****************/
/*
    We have a pair entry. first element is to record input x, the second one
    record the runing min (the minimum val from index 0 to i.)
    All operations are T:O(1)
*/
class MinStack {
public:
    /** initialize your data structure here. */
    vector<pair<int,int>> vec;
    MinStack() {

    }

    void push(int x) {
        if (vec.size()==0) vec.push_back(make_pair(x,x));
        else vec.push_back(make_pair(x,min(x,vec.back().second)));
    }

    void pop() {
        vec.erase(vec.begin()+vec.size()-1);
    }

    int top() {
        return vec.back().first;
    }

    int getMin() {
        return vec.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
