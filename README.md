# LeetcodeAlgorithm
Practice of leetcode

## Question
- How to tell which method is the most suitable for the question? dp or divide and conquer?

## Note
- lower_bound & upper_bound (範例：[315.cpp](315.cpp))
```
【用途】針對「已經排序」的資料進行binary search。
vector <int> v;
sort(v.begin(), v.end());
lower_bound: 找出vector中「大於或等於」val的「最小值」的位置：
auto it = lower_bound(v.begin(), v.end(), val);
upper_bound: 找出vector中「大於」val的「最小值」的位置：
auto it = upper_bound(v.begin(), v.end(), val);
```
- range sum / subarray sum
```
XXXXXXXXXX
   i    j
要求 [i, j] range sum，需直覺想到 presum[j] - presum[i-1]
```
- 區間是有排列，欲求得在此區間 [lower, upper] 的 num 數量
```c++
for (int i = start; i <= middle; i++) {
    auto a = lower_bound(presums.begin() + middle + 1,
                        presums.begin() + end + 1, presums[i] + lower_);
    auto b = upper_bound(presums.begin() + middle + 1,
                        presums.begin() + end + 1, presums[i] + upper_);
    count += b - a;
}
```
- Longest/shortest substring/subarray 直覺想到 two pointers, dp
- unordered_map default int value is 0.
    ```c++
    unordered_map<int, int> um;
    if (um[2]) { do sth. } // 此刻 um[2] == 0
    ```
- To get previous/next iterator
    ```
    next(it)
    prev(it) 
    ```
- Set in C++ is implemented with BST. Its lowerbound/upperbound is implemented with binary search.
- Whenever encounter index operation like the following
    ```c++
    for (int i= ...)
        for (int j= ...)
            `dp[i-1][j+nums[i]]`
    ```
    Please be careful about index boundary to avoid segmentation error.
- circular 
    - 直覺可以用 modulo operator
    - We can split case to discuss that pick the first element or not like [198.cpp](198.cpp)

## Basic Concept 
### Sort
- [quicksort](quicksort.cpp)
- Subsets | [78.cpp](78.cpp)
### Search
- [binary_search](binary_search.cpp)
- [level_order_traversal](level_order_traversal.cpp)
### Misc
- [Catalan number](https://hackmd.io/4EJpycUQTv2dnqzVr8uTvA)

## Two pointers
| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 209| Minimum Size Subarray Sum|[209.cpp](209.cpp)|M||  |
| 904| Fruit Into Baskets|[904.cpp](904.cpp)|M||  |

## Pattern: Subsets，子集类型，一般都是使用多重DFS
| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 78| Subsets|[78.cpp](78.cpp)|Medium|recursive,iteration, bit manipulation|  |
| 416| Partition Equal Subset Sum|[416.cpp](416.cpp)|Medium|recursive, dp, bit manipulation|   | <3 |

## Binary search
| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 744| Find Smallest Letter Greater Than Target|[744.cpp](744.cpp)|Easy| binary search|  |
| 1818| Minimum Absolute Sum Difference|[1818.cpp](1818.cpp)|Medium| binary search| |  <3|

## Stack
- 以後看到 circular 要有直覺可以用 modulo operator
- 看到 next greater/smaller element, 就要有直覺用 stack
- 看到 paraentheses, 就要有直覺用 stack

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 496| Next Greater Element I|[496.cpp](496.cpp)| Easy| Stack|  | 
| 503| Next Greater Element II|[503.cpp](503.cpp)| Medium| Stack|  | 
| 856| Score of Parentheses|[856.cpp](856.cpp)| Medium| Stack, stack as tree| | <3 |
| 901| Online Stock Span|[901.cpp](901.cpp)| Medium| Stack| | |
| 907| Sum of Subarray Minimums|[907cpp](907cpp)| Medium| Double Stack to decide number of subarray | | |

## Top K Elements
注意这种模式下，咱们不需要去排序数组，因为堆具有这种良好的局部有序性，这对咱们需要解决问题就够了
- 用 heap (In c++, By default a max heap is created ordered by first element of pair.)
- 如果你需要求最大/最小/最频繁的前K个元素
- 如果你需要通过排序去找一个特定的数

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 347| Top K Frequent Elements|[347.cpp](347.cpp)| Medium| Heap, bucket sort|  | 
| 215| Kth Smallest Number|[215.cpp](215.cpp)| Medium| Heap, bucket sort|  | 

## Pattern: K-way merge，多路归并
- 该问题的输入是排好序的数组，链表或是矩阵
- 如果问题让咱们合并多个排好序的集合，或是需要找这些集合中最小的元素

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 21| Merge Two Sorted Lists|[21.cpp](21.cpp)| Easy| dummy node|  | 
| 23| Merge k Sorted Lists|[23.cpp](23.cpp)| Hard| min heap, divide & conquer|  | <3<3 |
| 378| Kth Smallest Element in a Sorted Matrix|[378.cpp](378.cpp)| Medium| |  | <3 |

## Sort 
| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 148| Sort List|[148.cpp](148.cpp)| Medium| | n | 

## Bit Manipulation
- string 的方向跟 bit 是相反過來的，要小心
    - ex: `str[str.size() - 1 - i])`
- Bit &, |, 等 bit operator 優先順序很低，最保險就是全部都括號起來
    - ex: ```if (((status >> i) & 1) == 0)```

## Dynamic programming
- 动态规划的套路：从入门到精通到弃坑 [(slides)](https://docs.google.com/presentation/d/1oMZLZK8hpUNAUStWZmonG6lZQ4kl3lna3cWI_2yWLBg/edit#slide=id.p)
- Thinking template [(link)](https://hackmd.io/5rkBMkh1TqisTJ3LAIb-Pg)
- 之前儲存的欄位若沒有需要用到，space 都可以再壓縮。比如 dp[i][j] = min({dp[i - 1][j], ...})，因為先後狀態可以存到同一個欄位裡
    - 見 [322.cpp](322.cpp)
- 只要在 access index 有做運算的，(ex:  dp[j - coins[i]])，記得都要檢查邊界
- 通常 dp 都是要求我們求得數量，如果要我們也列出過程，就加個 prev storage 即可 [(link)](https://youtu.be/Uk9JRbylA0c?t=1143)

### Basic (时间序列型)
- 给出一个序列（数组/字符串），其中每一个元素可以认为“一天”，并且“今天”的状态只取决于“昨天”的状态。
- 欲更新的狀態只跟前一個狀態有關係，可以節省 space O(n) -> O(1)，也就是儲存 space 用 array -> variable

template:
```c++
// transfer function
status_var = ..;
for (int i = 0; i < n; i++) {
    /* Do operation on status_var */
    status_var = max(...); // or
    status_var = min(...);
}
```

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 121| Best Time to Buy and Sell Stock|[121.cpp](121.cpp)|E|||
| 123| Best Time to Buy and Sell Stock III|[123.cpp](123.cpp)|H| 好難！狀態轉移方程| Q | <3|

### Basic II (时间序列加强版)
- 给出一个序列（数组/字符串），其中每一个元素可以认为“一天”：但“今天”的状态 和之前的“某一天”有关，需要挑选。

template:
```c++
// transfer function
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        ...
    }
}
```

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 368| Largest Divisible Subset|[368.cpp](368.cpp)|M|| <3|
| 300| Longest Increasing Subsequence|[300.cpp](300.cpp)|M|||

### Basic III (双序列型)
- dp[i][j] 一定是由 dp[i-1][j-1], dp[i-1][j], dp[i][j-1] 三者求得
- 给出两个序列s和t（数组/字符串），让你对它们搞事情。
    - Longest Common Subsequences 
    - Shortest Common Supersequence
    - Edit distances
    - ...
套路：
定义dp[i][j]：表示针对s[1:i]和t[1:j]的子问题的求解。
千方百计将dp[i][j]往之前的状态去转移：dp[i-1][j], dp[i][j-1], dp[i-1][j-1]
最终的结果是dp[m][n]

template:
```c++
// transfer function
for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
        ...
    }
}
```

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 1143| Longest Common Subsequence|[1143.cpp](1143.cpp)|M|| |
| 1092| Shortest Common Supersequence|[1092.cpp](1092.cpp)|H| 往回找路徑還沒有很熟，去翻 algo| y|

### Basic IV (第I类区间型)
- 给出一个序列，「明确」要求分割成K个连续区间，要你计算这些区间的某个最优性质
- dp definition(這最難想)：`dp[i][k]` represents `s[1:i]` 分成k个区间，此时能够得到的最优解
- 搜寻「最后一个」区间的起始位置j，将 `dp[i][k]` 分割成 `dp[j-1][k-1]` 和 `s[j:i]` 两部分: `XXXX [j XXX i]`

template:
```c++
// transfer function
for (int i=1; i <= str_len;i++) {
    for (int k=1; k <= min(i, K); k++) {
        for (int j=k; j <= i; j++) {
            dp[i][k] = min{ dp[j-1][k-1] + helper(s, j, i) }
        }
    }
}
```

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 1278| Palindrome Partitioning III|[1278.cpp](1278.cpp)|H|| |
| 813| Largest Sum of Averages|[813.cpp](813.cpp)|M|| |<3|

### Basic V (第II类区间型)
- 只给出一个序列S（数组/字符串），求一个针对这个序列的最优解。
- 适用条件：这个最优解对于序列的index而言，具有「无后效性」。即无法设计dp[i]使得dp[i]仅依赖于dp[j] (j<i). 但是大区间的最优解，可以依赖小区间的最优解。
- 套路：
    - 定义dp[i][j]：表示针对s[i:j]的子问题的求解。
    - 千方百计将大区间的dp[i][j]往小区间的dp[i’][j’]转移。
    - 第一层循环是区间大小；第二层循环是起始点。
    - 最终的结果是dp[1][N]

template:
```c++
// transfer function
for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
        int j = i + len - 1;
        ...
    }
}
```

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 516| Longest Palindromic Subsequence|[516.cpp](516.cpp)|M| | | |
| 312| Burst Balloons|[312.cpp](312.cpp)|H| | | |

### 状态压缩
- 記著，只要狀態數量皆小於 32 bits 能夠表示的最大數，那麼可以用 `int` 來當作 bit mask 紀錄狀態，節省space

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 691| Stickers to Spell Word|[691.cpp](691.cpp)|H| bit manipulation| | <3|
| 1125| Smallest Sufficient Team|[1125.cpp](1125.cpp)|H| | ||

### 0/1 Knapsack Problem
- 背包問題就是選擇一個最理想的物品子集合(subset)

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 494| Target Sum|[494.cpp](494.cpp)|Medium| dp, offset| | <3 |

### Unbounded Knapsack
- 按照順序迭代，很自然就會是 combination
template:
```c++
/* 兩個迴圈已經有考慮到同個 coin 重複使用！ */
for (int i = 0; i < coins.size(); i++) {
    for (int j = coins[i]; j <= amount; j++) {
    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
    }
}
```

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 322| Coin Change|[322.cpp](322.cpp)|Medium| | | <3|
| 518| Coin Change 2|[518.cpp](518.cpp)|Medium| | | |

### Fibonacci numbers (dual status)
- `adjacent` 關鍵字！ 很可能就是用 Fibonacci
- 要注意 status initialization: `dp[1] = max(nums[0], nums[1])`，不要寫成 `dp[1] = nums[1]`

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 509| Fibonacci Number|[509.cpp](509.cpp)|Easy| | | |
| 198| House Robber|[198.cpp](198.cpp)|Medium| | | |
| 213| House Robber II|[213.cpp](213.cpp)|Medium| | | |

### Palindromic Subsequence

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 516| Longest Palindromic Subsequence|[516.cpp](516.cpp)|M| | | |
| 5| Longest Palindromic Substring|[5.cpp](5.cpp)|M| 還有另一個O(n)的演算法還沒搞懂| y| <3 |

## Tree
- BST 用 inorder traversal 一定是排序的
- edges.length == n - 1
- Tree 是沒有 cycle 的，可以結合 topological sort

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 144| Binary Tree Preorder Traversal|[144.cpp](144.cpp)|Easy| | | |
| 144| Binary Tree Postorder Traversal|[144.cpp](144.cpp)|Easy| | | |
| 530| Minimum Absolute Difference in BST|[530.cpp](530.cpp)|Easy| bst| | |
| 96| Unique Binary Search Trees|[96.cpp](96.cpp)|M| catalan number | | |

## Hash
### Rolling Hash

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 1044| Longest Duplicate Substring|[1044.cpp](1044.cpp)|Hard| Rolling hash|  | <3|
| 1554| Strings-Differ-by-One-Character|[1554.cpp](1554.cpp)|Hard| Rolling hash(Google interview)| | <3|
| 49| Group Anagrams|[49.cpp](49.cpp)|M| | | <3|

## Topological Sort
[link](https://leetcode.com/tag/topological-sort/)

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 207| Course Schedule|[207.cpp](207.cpp)|Medium| |  | <3|
| 210| Course Schedule II|[210.cpp](210.cpp)|Medium| |  | |
| 310| Minimum Height Trees|[310.cpp](310.cpp)|Medium| 不要從中心往外走，反過來從外走向裡面, level traversal|  |  <3|
| 269| Alien Dictionary|[269.cpp](269.cpp)|Medium| |  | |

## Bit Manipulation
- __builtin_popcount(bit_mask) // count the number of one’s(set bits) in an integer.
    - std::bitset<32>(bit_mask).count() // same as above.

### XOR

- XOR property
    - a^a = 0
    - a^0 = a
    - Commutative property: a^a^b^c = c^a^b^a = b^c
- num &= -num;  // find the rightmost different bit.
    - 要注意 num = -2147483648 會 overflow
- log2(num &= -num)： // find the idx of the rightmost set bit

| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 137| Single Number II|[137.cpp](137.cpp)|Medium| |  | <3|
| 260| Single Number III|[260.cpp](260.cpp)|Medium| |  | |

### Bit Mask
| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 1239| Maximum Length of a Concatenated String with Unique Characters|[1239.cpp](1239.cpp)|Medium| 錯了非常多次 |  | <3|
| 1284| Minimum Number of Flips to Convert Binary Matrix to Zero Matrix|[1284.cpp](1284.cpp)|Hard| 史上錯最多次，我對 matrix 操作還要再熟練！|  |  <3|

## Divide and Conquer
| #    | Title             | Solution | Difficult |         Note           | Question | Favorite |
| ---- |-------------------|----------|-----------|------------------------| ---- | ---- |
| 315| Count of Smaller Numbers After Self|[315.cpp](315.cpp)|H|  |  | |
| 327| Count of Range Sum|[327.cpp](327.cpp)|H| pass on local; but fail on leetcode?|  y| |
| 53| Maximum Subarray|[53.cpp](53.cpp)|E|  |  | |

## Note
2022.03.29
- [904.cpp](904.cpp)
    - Mistype `basket[fruits[right]]` to `basket[right]`.
2022.03.30
- [78.cpp](78.cpp)
    - Mistype `i >> j & 1` to `i >> j`.
2022.04.01
- [496.cpp](496.cpp)
    ```c++
    stack.top()
    /* Do something */
    stack.pop() // Always forget!
    ```
2022.04.04
- [300.cpp](300.cpp)
    - Mistype `dp[i] = max(dp[i], dp[j] + 1)` to `dp[i] = dp[j] + 1`. We have to check whenever updating dp array.
2022.04.08
- [1092.cpp](1092.cpp)
    - Mistype less to less and equal symbol
        ```c++
        /* error while sub_str is 'ab' */
        for (int i = 0; i <= len / 2; i++) { // --> for (int i = 0; i < len / 2; i++)
            if (sub_str[i] != sub_str[len - 1 - i]) ++num_change;
        }

        ```
2022.04.10
- [494.cpp](494.cpp)
    - Change iter variable inside iteration.
    ```c++
    // Do not change iter variable inside iteration
    for (int i = 1; i <= n; i++) {
        for (int j = -sum; j <= sum; j++) {
            j += offset; // wrong here
            ...
        }
    }
    ```
2022.04.11
- [494.cpp](494.cpp)
    - ±0 value is the same, 若以下操作會少考慮到其中一個情況
    ```c++
    if (idx == nums.size() - 1) {
      if (target == nums[idx]) {
        ...
      }
      else if (target == -nums[idx]) {
        ...
      }
    }
    ```
2022.04.13
- [322.cpp](322.cpp)
    - integer overflow happend!!
    ```c++
    class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int n = coins.size();
            vector<int> dp(amount+1, INT_MAX);
            ...
            for (int i=1; i <= n; i++) {
                for (int j=coins[i]; j <= amount; j++) {
                    dp[j] = min(dp[j], dp[j-coins[i]] + 1);
                }
            }
            
            return dp[amount] == INT_MAX ? -1 : dp[amount];
        }
    };
    ```

## New Word
1. wrap around
    - Note that the letters wrap around. For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
2. such that
    -  Return an array ans of length nums1.length `such that` ans[i] is the next greater element
3. where
    - You are given two distinct 0-indexed integer arrays nums1 and nums2, `where` nums1 is a subset of nums2.
4. the first xxx number to its ... in the array
    - The next greater number of a number x is the first greater number to its traversing-order next in the array
5. The `Subscript` or Array Index Operator is `denoted` by '[]'. This operator is generally used with arrays to retrieve and manipulate the array elements.
6. Given a set of `distinct` positive integers nums, return the largest subset answer `such that` every pair (answer[i], answer[j]) of elements in this subset `satisfies`: ...
7. A subsequence is a sequence that can be `derived` from an array by deleting some or no elements without `changing the order` of the `remaining` elements.

## Interview Question
1. 416 | Partition Equal Subset Sum | Medium
2. | 856| Score of Parentheses|[856.cpp](856.cpp)| Medium| Stack, stack as tree| | <3 |
3. 1818
4. 368