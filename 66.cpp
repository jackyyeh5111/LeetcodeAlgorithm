class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i]++;
                carry = false;
                break;
            }
        }

        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

/* 
    9 9
    0 0
    carry: true
 */