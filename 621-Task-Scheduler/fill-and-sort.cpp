class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> char_freq;
        int max_freq = 0;
        for (char task : tasks) {
            char_freq[task]++;
            max_freq = max(max_freq, char_freq[task]);
        }
        
        int num_char_max_freq = count_if(char_freq.begin(), char_freq.end(), 
                [max_freq](const auto &pair){return pair.second == max_freq;});
        
        int min_interval = (max_freq - 1) * (n + 1) + num_char_max_freq;
        return tasks.size() < min_interval ? min_interval : tasks.size();
    }
};

/* 
    n = 4
    ABCDEF
    ABCDEF
    AB

    A:3
    B:3
    C:2
    D:2
    E:2
    F:2

    min_interval = (max_freq - 1) * (n + 1) + num_char_max_freq
    if task.size < min_interval:
        return min_interval
    else
        return task.size
 */