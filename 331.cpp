class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "#") return true;
        
        stack<int> stk;
        int start = 0;

        // "9,3,4,#,#,1,#,#,2,#,6,#,#"
        // stk: [0, 0, 1]
        for (int end = 0; end < preorder.size(); end++) {
            char ch = preorder[end];
            if (ch == ',') {
                string word = preorder.substr(start, end - start);
                if (word == "#") {
                    if (stk.empty()) return false;
                    stk.top()++;
                    while(stk.top() == 2) {
                        stk.pop();
                        if (stk.empty()) return false;
                        stk.top()++;
                    }
                }
                else {
                    stk.push(0);
                }
                start = end + 1;
            }
        }
        // handle the last node
        string word = preorder.substr(start);
        if (word != "#") return false;
        if (stk.empty()) return false;
        stk.top()++;
        return stk.top() == 2;
    }
};

/* 
    stack: [count=0, count=1, ...]

    1. For BT, each node has two child nodes, either null or node instance.
    2. Once run into '#', stk.top()++
    3. Once stk.top() == 2, pop out. And stk.top()++
    4. During process, stack cannot be empty after pop, because tree is a connectede graph


    "9,3,4,#,#,1,#,#,2,#,6,#,#"
    stack: []

                       [9]  
                /              \
             [3]                 [2]   
           /     \                   \
        [4]       [1]                 [6]    

     "9,#,#,1"
    stack: [count=0]

    edge case: (during process, stack cannot be empty, because tree is a connectede graph)
    "9,#,#,1,#,#"
 */