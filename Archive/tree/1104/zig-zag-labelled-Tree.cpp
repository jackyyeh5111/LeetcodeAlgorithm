class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        int level = 0;
        int tmp = label;
        while(tmp!=0){
            level++;
            cout<<tmp;
            tmp = tmp>>1;
        }

        int real_label = label;
        bool changed = false || level%2!=0;
        while(label!=0) {
            if (level%2==0) {
                int start = pow(2, level-1);
                int end = pow(2, level)-1;
                int fake = end - label + start;
                result.insert(result.begin(),fake);
                if(!changed) {
                    label = fake;
                    changed = true;
                }
            }
            else{
                result.insert(result.begin(),label);
            }
            level--;
            label = label>>1;
        }
        result[result.size()-1] = real_label;
        return result;
    }
};

// Actually we can think that each level are doing reverse (zig-zag).
vector<int> pathInZigZagTree(int label, int level = 0) {
  while (1 << level <= label) ++level;
  vector<int> res(level);
  for(; label >= 1; label /= 2, --level) {
    res[level - 1] = label;
    label = (1 << level) - 1 - label + (1 << (level - 1));
  }
  return res;
}
