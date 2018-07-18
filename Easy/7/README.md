# [7] Reverse Integer

## 1. Problem:
Given a 32-bit signed integer, reverse digits of an integer.

Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [$$$-2^21$$$, $$$2^31 − 1$$$]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Example:
```
Input: 123
Output: 321
```
## 2. Note:
To reverse integer, just need to recursively add the low significant digit and the reversed number multiplied by 10, the reversed number is initialed as 0.

For checking INTEGER(32 bit) overflow, check if the cumulated reverse number is larger than INT_MAX / 10.


## 3. [Leetcode Link](https://leetcode.com/problems/reverse-integer/description/)
