
// class ListNode {
//   public:
//     int val=0;
//     ListNode* next=0;
//     ListNode(){};
//     ListNode(int val) : val(val);

// };

#include <map>
class Solution {
public:
    // Black-red tree: O(nlogn)
    // sort in each node: worst case O(n^2)
    // insert O(n)
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        map<int,ListNode*> sorted;
        for(vector<int> person : people){
            int val = person[0];
            int large_count = person[1];
            ListNode* node = new ListNode(large_count);
            if (sorted.find(val)==sorted.end()) sorted[val] = node;
            else {
                ListNode* p=0; ListNode* q=sorted[val];
                while(q&&q->val<large_count) {p=q; q=q->next;}
                if(!p) {
                    node->next = sorted[val];
                    sorted[val] = node;
                }
                else {
                    node->next=p->next;
                    p->next = node;
                }
            }

        }
        vector<vector<int>> result;
        for (auto it=sorted.rbegin();it!=sorted.rend();it++){
            ListNode* node = it->second;
            do {
                int order = node->val;
                int val = it->first;
                result.insert(result.begin()+order, vector<int>{val,order});
                node=node->next;
            } while(node);
        }
        return result;
    }
};
