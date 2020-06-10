class Solution {
public:
    // Passed Test Cases: 145/151
    // arg_idx ordered large->small->medium is in valid.
    // but not guarenteed in the other way around.
    /*
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size()<3) return true;

        for(int i=0; i<popped.size()-2;++i){
            int a = popped[i];
            int b = popped[i+1];
            int c = popped[i+2];
            int a_idx = findIdxByValue(pushed, a);
            int b_idx = findIdxByValue(pushed, b);
            int c_idx = findIdxByValue(pushed, c);
            cout << a_idx <<" "
                 << b_idx <<" "
                 << c_idx <<endl;
            if (b_idx<a_idx && b_idx<c_idx && c_idx<a_idx) return false;
        }
        return true;
    }

    int findIdxByValue(vector<int> elements, int element)
    {
        auto it = std::find(elements.begin(), elements.end(), element);
        return std::distance(elements.begin(), it);
    }
    */

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        
    }
};
