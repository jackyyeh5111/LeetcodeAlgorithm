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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // divide & conquer
        // T: O(nlogk), S:O(1) in place.
        if (lists.size()==0) return 0;
        int skip = 1;
        while(skip < lists.size()) {
            for (int i=0; i<lists.size()-skip; i+=skip*2) {
                lists[i] = merge2Lists(lists[i], lists[i+skip]);
            }
            skip *= 2;
        }

        return lists[0];
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* header = new ListNode(0);
        ListNode* tail=header;
        while (l1&&l2) {
            if (l1->val < l2->val){
                tail->next = l1;
                l1=l1->next;
            }
            else{
                tail->next = l2;
                l2=l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        tail = header;
        header=header->next;
        delete tail;
        return header;

    }
};

/**********************************************/

// Another iterating  approach for divide & conquer
// Each iteration, we take first 2 entries to merge.
// T: O(nlogk), S: O(1)
ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.empty()){
        return nullptr;
    }
    while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists.front();
}
