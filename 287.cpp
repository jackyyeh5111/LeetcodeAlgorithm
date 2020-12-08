/***** Third Visit *****/
/*
    By pegeon-hole theory, there must exist one duplicate num.
    Constraint:
        Less than T:O(n^2), S:O(1)
    -----
    [1,3,4,2,2] 4 kind of values w. 5 times
     0 1 2 3 4 <- 4 kind of values can map to index
    Use bit manipulation could save time to T:O(n)/S:O(1)
    WRONG ANSWER, we could have multiple times of duplicate num.
    -----
    Use a map to record seen values.
    T:O(n)/S:O(n)
    -----
    Use sign bit to record if seen. This will alter the original value.
    T:O(n)/S:O(1)
    -----
    TREAT IT AS LIST, find cyclic & intersection
    2*(x+k)=x+k+cm
    x+k=cm
    x=cm-k <--- means that we can start at the slow/fast meet point.
    [1,3,4,2,2]
     0 1 2 3 4

     0->1->3->2->4-
              ^---|
    [3,1,3,4,2]
     0 1 2 3 4

     0->3->4->2-
        ^------|
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow=0,fast=0;
        bool begin=true;
        while (begin||nums[slow]!=nums[fast]) {
            slow=nums[slow];
            fast=nums[nums[fast]];
            begin=false;
        }
        slow=0;
        while (nums[slow]!=nums[fast]) {
            slow=nums[slow];
            fast=nums[fast];
        }
        return nums[fast];
    }
};

/***** Second Visit *****/
/*
    Use a hashmap and check count
    T:O(n)/S:O(n)
    -----------
    Here we have all entry with positive value, we can use sign bit as existed
    flag. But space complexity is O(n)
    T:O(n)/S:O(n)
    -----------
    prove: induction
    -----------
    Treat it as linked list, next ptr is the value of entry.
    T:O(n)/S:O(n)
    2 pass
    2*(x+k)=x+cm+k
    > x+k=cm
    > x=cm-k
    x+k+x=x+k+cm-k=x+cm
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow=nums[0],fast=nums[0];
        bool begin=true;
        while(begin||slow!=fast) {
            slow=nums[slow];
            fast=nums[nums[fast]];
            begin=false;
        }
        slow=nums[0];
        while(slow!=fast) {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        for(int num : nums) {
            num=abs(num);
            if (nums[num-1]<0) return num;
            nums[num-1]*=-1;
        }
        return -1;
    }
};

/***** First Visit *****/
/*
    Reduce to  Floyd's Tortoise and Hare (Cycle Detection).
    The cycle appears because nums contains duplicates. The duplicate node is a cycle entrance.
    想法:
        slow & fast pointer (龜兔賽跑)
        slow 走一步，fast 走兩步，如果遇到就是有 cycle。
        如何找出 cycle node 呢?
        假設 cycle 長度為 m:
        (1) 假設 slow 走 K 步，代表 fast 走了 2K 步，此時相遇了，代表了 fast
            比 slow 多繞了迴圈至少一次，因此 (2K - K) = n * m
        (2) 此時一個人從起點開始走，另外一個人從相遇點開始走(一次都走一步)，
            會在 cycle node 相遇，為什麼?
        原因:
        從起點走到相遇點是 K，而 K = n * m (迴圈的倍數)，因此這兩個人至少一定會在剛剛的相遇點相遇。 而他們要能夠再相遇點相遇，則必定在 cycle node 就要遇到，才能夠一起走到相遇點!

        把題目想成解 Linked List Cycle。
        Index 當成 node，Value 當成連接的下一個 node
        [1,3,4,2,2]
        FirstNode = Index 0
        SecondNode = FirstNode->next = Index 1
        ThirdNode = SecondNode->next = Index 3
        一個 pointer 走一步，另一個 pointer 走兩步，有迴圈的話必定會停在同一點上。此時把一個 pointer 拉回起點，兩個 pointer 每次走一步，相遇點就是迴圈的起始。
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        /*
            Obviously we should have a O(n) space to record each entry and have comparison on it.
            But now we are asked to have O(1) space only, thus we could use bit operation?
            It would fail on this case: [5,1,4,2,2]
            1 0 1
            2 0 1
            2 0 2
            2 1 2
            2 2 2
            Reduce to "Find Majority?"
        */
        int slow=0, fast=0;
        while(true) {
            fast=nums[nums[fast]];
            slow=nums[slow];
            if(slow==fast) {slow=0; break;}
        }
        while(true) {
            fast=nums[fast];
            slow=nums[slow];
            if (slow==fast) return slow;
        }
        return -1; // not found
    }
};
