class Solution {
public:
    string multiply(string num1, string num2)
    {
        // T:O(mn), could be replaced with divide & conquer T(n)=4T(2=n/2)+cn
        if (num1=="0"||num2=="0") return "0";
        if (num1=="1") return num2;
        if (num2=="1") return num1;

        int m = num1.size(), n = num2.size();
        string ans(m + n, '0');
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');
                ans[i + j + 1] = sum % 10 + '0';
                ans[i + j] += sum / 10;
            }
        }
        for (int i = 0; i < m + n; i++) {
            if (ans[i] != '0') {
                return ans.substr(i);
            }
        }
        return "0";
    }
};
