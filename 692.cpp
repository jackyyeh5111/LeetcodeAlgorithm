/*
    1 pass: word counting
        k: word, v: frequency
    T:O(n)/S:O(N)

    2 pass: construct a max heap
        <frequency, word>
    T:O(N)/S:O(n)

    3 pass: k times of pop operation
    T:O(klogn)
*/
typedef pair<int, string> pis;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        // 1 pass
        unordered_map<string,int> cnter;
        for ( auto &word:words) cnter[word]++;

        // 2 pass
        auto comp=[&](pis &a, pis &b){
            if (a.first==b.first) return a.second>=b.second;
            else return a.first<=b.first;
        };
        priority_queue<pis,vector<pis>,decltype(comp)> pq(comp);
        for (auto it=cnter.begin(); it!=cnter.end(); ++it) {
            pq.push({it->second, it->first});
        }


        // 3 pass
        vector<string> ans;
        while (k--) {
            auto t=pq.top(); pq.pop();
            ans.push_back(t.second);
        }
        return ans;
    }
};
