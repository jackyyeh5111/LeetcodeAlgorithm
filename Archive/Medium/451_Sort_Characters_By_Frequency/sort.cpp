class Solution {
public:

    string frequencySort(string s)
    {
        map<char, int> record;
        for (const char& c : s) {
            if (record.find(c) != record.end())
                record[c] += 1;
            else
                record[c] = 1;
        }
        vector<pair<char,int>> vec;
        for (auto it=record.begin(); it!=record.end(); ++it) {
            vec.push_back(make_pair(it->first, it->second));
        }
        sort(vec.begin(), vec.end(), [](const pair<char,int> &p1, const pair<char,int> &p2){
            return p1.second > p2.second;
        });

        string result;
        for (auto item : vec) {
            for (int i=0; i<item.second; ++i)
                result += item.first;
        }
        return result;
    }
};
