/* 
    Space: O(1)


    Optimize: use vector in place as stack, space complexity: O(1)
 */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int stackPtr = 0; // Simulating stack with the pushed array
        int popPtr = 0;   // Pointer for the popped array
        
        for (int i = 0; i < pushed.size(); i++) {
            pushed[stackPtr++] = pushed[i]; // Push element onto "stack"
            while (stackPtr > 0 && pushed[stackPtr - 1] == popped[popPtr]) {
                stackPtr--; // Pop from "stack"
                popPtr++;
            }
        }
        return stackPtr == 0;
    }
};



class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int ptr = 0;
        for (int i = 0; i < pushed.size(); i++) {
            stk.push(pushed[i]);
            while(!stk.empty() && stk.top() == popped[ptr]) {
                stk.pop();
                ptr++;
            }
        }
        return stk.empty();
    }
};

/* 
    1 2
    
    2 1
      ^ 
 */