# LeetCode Notes


## General
 - overflow?
 - check the input length
   - short->backtracking / long->DP
 - lexicographical order: "abcd" < "bacd"
 - **Once we have TLE via recursive(backtracking), there must be a solution with DP. If still not work, add early stop strategy for large edge case.**

## Dynamic Programming
 - catalan number: 1/(n+1)C^2n_n, T:O(3^n)


### Possible process of thinking [Induction]
 - Since DP means optimal substructure which is closed to mathematical induction, in many dp problems, there can be some n represent array size, string length, tree height, etc.
 - Then you consider the situation when n=1, n=2, n=3, n=4, n=5, ..., this procedure may cost lots of time until you found many processes are repeated and can be cached. You can cache whatever you want. Remember don't directly define what your dp array cache and solve the problem by your definition. You solve the problem then you define what dp cache.
 - In this way, you found the so-called Bellman equation.
 - Problems which doesn't have an obvious n, or doesn't have such n(such as each dp used to save a statement), or has two or more n-s, are often hard to solve.
 - Figure out whether P(a+1,b+1) can be solved by P(a,b+1) and P(a+1,b), then you will find P(a+1,b+1) = P(a,b+1)+P(a+1,b)-P(a,b)+D(a+1,b+1)(Inclusion–exclusion principle)


## Searching
Refer: https://leetcode.com/discuss/general-discussion/786126/python-powerful-ultimate-binary-search-template-solved-many-problems

Template
 - Correctly initialize the boundary variables left and right. Only one rule: set up the boundary to include all possible elements;
 - Decide return value. Is it return left or return left - 1? Remember this: after exiting the while loop, left is the minimal k​ satisfying the condition function;
 - Design the condition function. This is the most difficult and most beautiful part. Needs lots of practice.
 - Notice overflow on left pointer since it might equal to length.
```python
def binary_search(array) -> int:
    def condition(value) -> bool:
        pass

    left, right = 0, len(array)
    while left < right:
        mid = left + (right - left) // 2
        # mid = (right + left) // 2
        if condition(mid):
            right = mid
        else:
            left = mid + 1
    return left
```


## Recursive / Backtracking
 - check input constraint in terms of length. If the length is too long, it might cause TLE, then we should consider applying DP solution.
 - check terminated criteria
 - comb/perm/subset


## Tree
 - Catalan number: 1/(n+1)C^2n_n, T:O(3^n)
 - Check order: NLR/LRN/LNR
 - Check what kind of info should we return
 - Iterative (Best Time):
     - Morris traversal(S:O(1))
         - for each node, check if its predecessor has a right chlid link to itself, then visit it.
 - recursive (Easy to code)


## Divide & Conquer


## LinkedList
 - header node
 - slow/fast ptr
 -

## Stack and Queue
 - mono stack. E.g. 456, 1673, 316, 1081


## String
 - TRIE
 - KMP
   - Failure function
 - Treat it as array, use moving window with start/end ptr. E.g. **Problem 76**


## Array
  - Could sort help?
      - If yes, could Bucket sort further helps?
          - e.g. [164](https://leetcode.com/problems/maximum-gap/)
  - binary search.
  - 2 ptr solution, i.e. left/right or start/end ptr.
  - Use a stack to record increasing index, i.e. mono stack. \[Greedy\]
    - e.g. [84](https://leetcode.com/problems/largest-rectangle-in-histogram)
    - e.g. [316](https://leetcode.com/problems/remove-duplicate-letters)
  - running ptr
  - 2-D Array:
      1. DP: split into small problems then cumulatively solve it.
      2. Backtracking: kind of enumerate all possible solutions.
      3. Greedy: divide & conquer if the 2-D matrix canbe splitted.


## Numeric


## Graph
 - Binary relationship is represented as a graph usually.
 - dfs/bfs/post-DFS
 - inverse of post dfs is one of a topological sort.

## Sorting
 - bucket/counting sort T:O(n)/S:O(n)
 - comparison sort
     1. quick sort: partition
     2. merge sort
     3. bubble/insert sort


## Design


## Union
 - find O(logn) / union O(1)
 - During find (parent), we need to update its parent also for speed up. With frequently updating its parent, we can have amortized complexity O(1)


 ## HashMap

 ## IOU Calculation
  - w: min(larger x of rec1 and rec2) - max(smaller x of rec1 and rec2)
  - h: min(larger x of rec1 and rec2) - max(smaller x of rec1 and rec2)
  - check if w>0 && h>0
