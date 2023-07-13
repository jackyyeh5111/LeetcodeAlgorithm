class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        n++; // important
        unordered_map<int, int> count;
        for (char task : tasks)
            count[task]++;

        priority_queue<int> pq; // max_heap
        for (auto pair : count)
            pq.push(pair.second);
    
        /* 
            tasks: ABAB
                n: 2 -> 3
         */
        int ans = tasks.size(); // 4 + 1 + 1
        while(!pq.empty()) { // []
            int num_pick = min((int)pq.size(), n); // 2
            vector<int> tmp; // []
            for (int i = 0; i < num_pick; i++) {
                int freq = pq.top();
                pq.pop();
                freq--;
                if (freq > 0)
                    tmp.push_back(freq);
            }

            if (tmp.size()) // do not have to add idle for the last round.
                ans += n - num_pick;
            
            // push back elements
            for (int num : tmp)
                pq.push(num);
        }
        return ans;
    }
};

/* 
    AAABC
    {3A, 3B, 1C}, n = 2
    ABCABIAB

     pq: []
    tmp: [1 1]

    See it as top N freq problem
 */


