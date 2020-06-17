class Solution {
public:
    string getPermutation(int n, int k)
    {
        // T:O(n), S:O(n)
        // k-1 for zero base indexing
        unordered_map<int,int> table;
        vector<char> vec;
        table[0]=1; table[1]=1; vec.push_back('1');
        for (int i=2; i<=n; ++i) {
            table[i]=table[i-1]*i;
            vec.push_back('0'+i);
        }
        string ans=""; k=k-1;
        for (int i=0; i<n; ++i) {
            int divide = k/table[n-1-i];
            cout<<divide<<endl;
            ans+=vec[divide];
            vec.erase(vec.begin()+divide);
            k = k-divide*table[n-1-i];
        }
        return ans;
    }
};
