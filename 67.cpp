class Solution {
public:
    string addBinary(string a, string b) {
        int size_a = a.size();
        int size_b = b.size();
        if (size_a < size_b)  // make sure a.size >= b.size
            return addBinary(b, a);

        int carry = 0;
        int idx_b = size_b - 1;
        string ans = "";
        for (int i = size_a - 1; i >= 0; i--) {
            int sum = 0;
            if (a[i] == '1') sum++;
            if (idx_b >= 0 && b[idx_b] == '1') sum++;
            if (carry) sum++;
            
            // update ans
            if (sum % 2) ans += '1';
            else ans += '0';

            carry = sum >= 2;
            idx_b--;
        }
        if (carry) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/* 
     a   11
     b   01
  carry 110      
        100
 */