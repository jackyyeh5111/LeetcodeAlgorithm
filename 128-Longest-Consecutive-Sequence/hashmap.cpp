class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    int max_seqlen = 0;

    // init visited map
    unordered_map<int, bool> visited;
    for (int num : nums) visited[num] = false;

    for (int num : nums) {
      if (visited[num]) continue;

      visited[num] = true;
      int seqlen = 1;  // itself

      // check left hand size
      int left = num - 1;
      while (visited.count(left)) {
        visited[left] = true;
        seqlen++;
        left--;
      }
      // check right hand size
      int right = num + 1;
      while (visited.count(right)) {
        visited[right] = true;
        seqlen++;
        right++;
      }

      // update max_seqlen
      max_seqlen = max(seqlen, max_seqlen);
    }
    return max_seqlen;
  }
};

/*
    clarification:
    1. int only

       nums: [5 1 2 3]

    max_seqlen

    1. convert it to hash map
        map = { // value -> visited
            5: true
            1: true
            2: true
            3: true
        }
    2. iterate check each element and find its corresponding max sequence.
 */