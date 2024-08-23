class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // count tasks
        const int NUM_ALPHABET = 26;
        vector<int> counter(NUM_ALPHABET, 0);
        for (char task : tasks)
            counter[task - 'A']++;
        
        // sort counter
        sort(counter.begin(), counter.end());

        int max_freq = counter.back();
        int num_with_max_freq = 0;
        for (int i = counter.size() - 1; i >= 0; i--) {
            if (counter[i] != max_freq)
                break;
            num_with_max_freq++;
        }
        int min_interval = (max_freq - 1) * (n + 1) + num_with_max_freq;
    
        if (tasks.size() > min_interval)
            return tasks.size();
        else
            return min_interval;
    }
};

/* 
    A B X
    A B X
    A B

    n = 2
    num_with_max_freq = 2
    min_interval = (max_freq - 1) * (n + 1) + num_with_max_freq
    total_task_cnt = 10
    if (total_task_cnt > min_interval)
        return total_task_cnt

    A:3
    B:3
    C:2
    D:2
 */