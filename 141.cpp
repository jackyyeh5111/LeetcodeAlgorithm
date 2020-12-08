/***** Second Visit *****/
 /*
     List: use slow/fast solution.
     T:O(n)/S:O(1)
 */
 class Solution {
 public:
     bool hasCycle(ListNode *head)
     {
         ListNode *slow=head,*fast=head;
         while(fast&&fast->next) {
             slow=slow->next;
             fast=fast->next->next;
             if (fast==slow) return true;
         }
         return false;
     }
 };

/***** First Visit *****/
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        /*
            use a set to store the visited node and check if duplicated, then we
            find circle.
            T:O(n), S:O(n)
            ------------------------
            use 2 ptr. slow with step 1 and fast with step 2.
            T:O(n), S:O(1)
            slow: n
            fast: 2n
            -> if there's a cycle, fast ptr can reach the slow ptr.
        */
        ListNode *slow=head, *fast=head;
        while(slow&&fast&&fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true; // cyclic
        }
        return false; // acyclic
    }
};
