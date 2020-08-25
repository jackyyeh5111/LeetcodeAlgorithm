/*
First count the number of occurrences of each element.

Let the max frequency seen be M for element E

We can schedule the first M-1 occurrences of E, each E will be followed by at
least N CPU cycles in between successive schedules of E

Total CPU cycles after scheduling M-1 occurrences of E = (M-1) * (N + 1) // 1
comes for the CPU cycle for E itself

Now schedule the final round of tasks. We will need at least 1 CPU cycle of the
last occurrence of E. If there are multiple tasks with frequency M, they will
all need 1 more cycle.

Run through the frequency dictionary and for every element which has frequency
== M, add 1 cycle to result.

If we have more number of tasks than the max slots we need as computed above we
will return the length of the tasks array as we need at least those many CPU
cycles.
*/
/*********** max usage counting ***********/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        /*
            AAABBB,n=0
                AAABBB -> 6
            AAABBB,n=1
                ABABAB -> 6
            AAABBB, n=2
                AB-AB-AB ->8
            AAABBBCCCDDD, n=2
                A__A__A
                (3-1)*(2+1)+4
        */
        unordered_map<char,int> m;
        int count=0;
        for (char c:tasks) {
            m[c]++;
            count=max(count,m[c]);
        }
        int ans=(count-1)*(n+1);
        for (auto it=m.begin(); it!=m.end(); ++it) {
            if (it->second==count) ans++;
        }
        return max(ans,(int)tasks.size());
    }
};

/*********** idle slots counting ***********/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> char_map (26, 0);

        for (char task: tasks) {
            char_map[task-'A']++;
        }

        sort(char_map.begin(), char_map.end());
        int max_val = char_map[25] - 1;
        int idle_slots = max_val * n;

        for (int i = 24; i >= 0; i--) {
            idle_slots -= min(char_map[i], max_val);
        }


        return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();

    }
};
