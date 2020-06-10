/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// We will accumulate the values.
// head’ : [3, 7,9,3,4,5,10,4]
// (Like an array), head'[i] = head[i] + head' [i-1]
// If we see repeated elements then we have to deleted
// ALG:
//   Iterate LinkedList from left to right
//   Process each accumulative value in map.
//   Given a current accumulative value check if exists in our map
//   (get previous element).
//   If they exist um[ac]->next = currentNode->next, then delete *intermediate*
//   nodes in our map between um[ac] and currentNode
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int, ListNode*> acum;
        ListNode* header = new ListNode(0);
        header->next = head;
        acum[0] = header;
        int sum = 0;
        while(head) {
            sum += head->val;
            if (acum.find(sum) == acum.end()) acum[sum] = head;
            else {
                ListNode* node = acum[sum]; ListNode* tail;
                tail = node->next;
                int temp_sum = sum;
                // Remeber to delete intermediate nodes, or it will cause wrong
                //   order in the following nodes.
                while (tail != head) {
                    temp_sum += tail->val;
                    acum.erase(temp_sum);
                    tail = tail->next;
                }
                node->next = tail->next;
            }
            head = head->next;
        }
        return header->next;
    }
};
