# [169] Majority Element


## Problem:
Given an array of size n, find the majority element. The majority element is the element that appears more than `⌊ n/2 ⌋` times.

You may assume that the array is non-empty and the majority element always exist in the array.


## Note:

### Sort:
If the numbers are sorted, then the majority element must be at the mid of the array.  
However, if the numbers are not sorted, then the time complexity will be `O(nlog(n))` since it's the lower bound of sorted algorithm.

### Boyer-Moore Majority Vote:
This algorithm can handle non-sorted array, which time complexity is `O(n)` and space complexity is `O(1)`.  
It requires two rounds. The first round will choose the candidate majority, and the second round is to verify the candidate is majority or not (i.e. appreas more than ⌊ n/2 ⌋).

#### First round:
>Initialize a majority candidate m and a counter i with i = 0
>For each element x of the input sequence:
>>If i = 0, then assign m = x and i = 1
>>else if m = x, then assign i = i + 1
>>else assign i = i − 1
>Return m

### Second round:
Check if `m` appears more than ⌊ n/2 ⌋.  

## [Leetcode Link](https://leetcode.com/problems/majority-element/description/)
