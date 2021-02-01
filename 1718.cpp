/*
    5
    [1,2,2,3,3,4,4,5,5]
    [5, , , , ,5, , ]
    constraints: 1<=n<=20 ==> backtracking!!!
*/
class Solution
{
public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> ans(n * 2 - 1, 0);
        vector<bool> visited(n, 0);
        help(ans, visited, 0, n);
        return ans;
    }

    bool help(vector<int> &ans, vector<bool> &visited, int idx, int n)
    {
        if (idx == ans.size())
            return true;
        else if (ans[idx] != 0)
            return help(ans, visited, idx + 1, n);
        for (int i = n; i >= 1; --i)
        {
            if (visited[i - 1])
                continue;
            int offset = i > 1 ? i : 0;
            if (idx + offset < ans.size() && ans[idx] != 0 && ans[idx + offset] != 0)
            {
                if (help(ans, visited, idx + 1, n))
                    return true;
            }
            else if (idx + offset < ans.size() && ans[idx] == 0 && ans[idx + offset] == 0)
            {
                visited[i - 1] = 1;
                ans[idx] = i;
                ans[idx + offset] = i;
                if (help(ans, visited, idx + 1, n))
                    return true;
                ans[idx] = 0;
                ans[idx + offset] = 0;
                visited[i - 1] = 0;
            }
        }
        return false;
    }
};