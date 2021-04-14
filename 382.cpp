/***** Third Visit *****/
/*
    1/i * i/(i+1) * (i+1)/(i+2) * ... = 1/n
    T:O(n)/S:O(1)
*/
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *head=0;
    Solution(ListNode* head) {
        this->head=head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *cur=head;
        int ret=0,counter=1;
        while (cur) {
            if (rand()%counter==0)
                ret=cur->val;
            counter++;
            cur=cur->next;
        }
        return ret;
    }
};

/***** Second Visit *****/
/*
    Resovour Sampling
    proof: 1/i x i/i+1 x ... x n-1/n = 1/n

    getRandom: T:O(n)
*/
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *head=0;
    Solution(ListNode* head)
    {
        this->head=head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int idx=1, ret=0;
        ListNode *cur=head;
        while (cur) {
            int k=rand()%idx;
            if (k==0) ret=cur->val;
            cur=cur->next;
            idx++;
        }
        return ret;
    }
};

/***** First Visit *****/
/*
    Resovour Sampling
    從S中抽取首k項放入「水塘」中
    對於每一個S[j]項（j ≥ k）：
    隨機產生一個範圍從0到j的整數r
    若 r < k 則把水塘中的第r項換成S[j]項

    For possibility of n over N nums
      1/n * 1-(1/(n+1)) * 1-(1/(n+2)) * ... * 1-(1/N)
    = 1/n * n/(n+1) * (n+1)/(n+2) * ... * (N-1)/N
    = 1/N

    T:O(n)/S:O(1)

    Refers: https://zh.m.wikipedia.org/zh-tw/%E6%B0%B4%E5%A1%98%E6%8A%BD%E6%A8%A3
*/
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *head=0;
    Solution(ListNode* head) {
        this->head=head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *cur=this->head;
        int i=1,ret=0;
        while (cur) {
            if (rand()%i==0)
                ret=cur->val;
            i++;
            cur=cur->next;
        }
        return ret;
    }
};
