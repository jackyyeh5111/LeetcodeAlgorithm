
/* 
    2-complement supports adding numbers with different sign.
 */
class Solution {
 public:
  int getSum(int a, int b) {
    do {
      int sum = a ^ b;
      int carry = a & b;
      a = sum;
      b = carry << 1;
    } while (b != 0);
    return a;
  }
};
