# [13] Roman to Integer

## 1. Problem:
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, *XII*, which is simply *X* + *II*. The number twenty seven is written as *XXVII*, which is *XX* + *V* + *II*.

Exanple:
```
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```
## 2. Note:
For each character, check its' next value. If the character is less than its' next value, then reduce it, and vice versa.

## 3. [Leetcode Link](https://leetcode.com/problems/roman-to-integer/description/)
