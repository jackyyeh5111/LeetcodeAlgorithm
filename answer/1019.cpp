/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head)
    {
        stack<pair<int,int>> s;
        vector<int> ans;
        int idx=0;
        while (head) {
            ans.push_back(0);
            while (!s.empty()&&s.top().first<head->val) {
                auto t=s.top(); s.pop();
                ans[t.second]=head->val;
            }
            s.push({head->val,idx++});
            head=head->next;
        }
        return ans;
    }
};
