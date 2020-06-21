/**************** revisit **********************/
class Solution {
public:
    string getPermutation(int n, int k)
    {
        /*
        1 2 3 k=2
        2 1 3
        ^ ceil(2/2), k=k-1

        1 2 3 4 k=9-1
        2 3 1 4
        ^ ceil(k/3!) k-=3!  2
        2 3 1 4
          ^
        */
        string ans="";
        vector<int> pow(n+1,0);
        vector<int> tmp;
        pow[0]=1;
        for (int i=1; i<=n; ++i) {
            pow[i]=pow[i-1]*i;
            tmp.push_back(i);
        }
        k--;
        while (k!=0) {
            cout<<n<<","<<k<<endl;
            int idx = k/pow[n-1];
            k=k-idx*pow[n-1];
            ans += (tmp[idx]+'0');
            tmp.erase(tmp.begin()+idx);
            n--;
        }
        for (int x:tmp) ans += (x+'0');
        return ans;
    }
};

/**************** first visit ******************/
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
