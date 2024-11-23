class Solution {
 public:
  double myPow(double x, int n) {
    double p = n;
    if (!p) return p + 1;
    if (p < 0) {  // if it is negetive power, make it a positive power
      p = abs(p);
      x = 1 / x;  // make x as 1/x
    }
    double k = myPow(x, p / 2);  // divide and conquer step
    // multiplying the subproblems
    if (n % 2)
      return x * k * k;  // if n is odd we have to multiply x also na
    else
      return k * k;  // otherwise we will return k directly.
  }
};