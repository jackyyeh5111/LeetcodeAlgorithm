/* 
    Another thought by chatGPT.
 */
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        // Sort the hand to maintain order
        sort(hand.begin(), hand.end());
        
        // Use a map to count frequencies
        map<int, int> freq;
        for (int num : hand) freq[num]++;

        // Iterate through each number in the hand
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int count = it->second;
            if (count > 0) {
                // Try to create a sequence starting from current number
                for (int i = 1; i < groupSize; i++) {
                    int nextNum = it->first + i;
                    if (freq[nextNum] < count) return false;
                    freq[nextNum] -= count;
                }
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) return false;
        unordered_map<int, int> value_to_cnt;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int num : hand)
            value_to_cnt[num]++;
        for (auto it = value_to_cnt.begin(); it != value_to_cnt.end(); it++)
            min_heap.push(it->first);

        // greedy

        /* 
            1 2 3 4
         */
        while(!min_heap.empty()) {
            int min_val = min_heap.top();
            // form a group
            for (int i = 0; i < groupSize; i++) {
                if (value_to_cnt[min_val + i] == 0) return false;
                value_to_cnt[min_val + i]--;
            }
            
            // update min_heap
            while(!min_heap.empty()) {
                if (value_to_cnt[min_heap.top()] > 0)
                    break;
                min_heap.pop();
            }
        }
        return true;
    }
};

/* 
   groupSize = 2
   1 2 3 4

   1 2
   3 4
 
    hashmap: // value -> cnt
        1: 0
        2: 0
        3: 1
        4: 1
 
    use min_heap to search for minimum value available to us

          1_ 
        /   \
      2_      3
    /   \
  4      5
  
 */