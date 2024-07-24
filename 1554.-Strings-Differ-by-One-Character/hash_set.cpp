/*
    O(m^2 * n), Use hashset, to insert all possible combinations adding a
   character "*". For example: If dict[i] = "abc", insert ("*bc", "a*c" and
   "ab*").
 */
class Solution {
 public:
  bool differByOne(vector<string>& dict) {
    unordered_set<string> Set;
    for (string str : dict) {
      for (int i = 0; i < str.size(); i++) {
        string encoded = str;
        encoded[i] = '*';
        if (Set.count(encoded)) return true;
        Set.insert(encoded);
      }
    }
    return false;
  }
};
