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
    int numComponents(ListNode* head, vector<int>& G) {
        // T:O(n),S:O(n)
        unordered_set<int> s(G.begin(),G.end());
        int ans=0;
        while(head) {
            if (s.find(head->val)!=s.end()) { // exist in G
                while(head->next&&s.find(head->next->val)!=s.end())
                    head=head->next;
                ans++;
            }
            head=head->next;
        }
        return ans;
    }
};
