
/*
    [5,7,5,7,4,5]
    <5,1> <7,1> <5,2> <7,2> <4,1> <5,3>
    max heap !! priority_queue<vector<int>,vector<vector<int>>,less>
    <freq, idx, val>
    The built-in sorting will sort by the order of vector
    use an additional map to record freq.
    T:o(nlogn)/S:O(n)
    -----
    In the first though, each time we pop out the num of max freq, Iwe should iterate over the freq map and see what's the second largest freq...

    but actually we can just check the size of the stack of stack map while pop out...

    T:O(n)/S:O(n)
*/

// T:O(nlogn)/S:O(n) with max heap.
class FreqStack {
public:
    priority_queue<vector<int>,vector<vector<int>>,less<vector<int>>> pq;
    unordered_map<int,int> mp;
    int idx=0;
    FreqStack() {

    }

    void push(int x) {
        mp[x]++;
        pq.push({mp[x],idx++,x});
    }

    int pop() {
        auto top=pq.top(); pq.pop();
        mp[top[2]]--;
        return top[2];
    }
};

// T:O(n)/S:O(n) with stack of stack
class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> order;
    int maxFreq=0;
    FreqStack() {

    }

    void push(int x) {
        freq[x]++;
        maxFreq=max(maxFreq,freq[x]);
        order[freq[x]].push(x);
    }

    int pop() {
        int ret=order[maxFreq].top(); order[maxFreq].pop();
        freq[ret]--;
        if (order[maxFreq].empty()) maxFreq--;
        return ret;
    }
};
