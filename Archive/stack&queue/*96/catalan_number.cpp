class Solution {
public:
    // Catalan Number
    int numTrees(int n)
    {
        return (int)(combination(2*n,n)-combination(2*n,n+1));
    }
    int combination(int n, int m)
    {
        vector<unsigned int> array(m+1,1);
        for (int i=0; i<n-m;++i){
            for(int j=1; j<=m; ++j)
                array[j] = array[j-1]+array[j];
        }
        return array[m];
    }
};

// Dynamic Programming
class Solution {
public:
    // Catalan Number
    int numTrees(int n)
    {
        vector<unsigned int> record(n+1,0);
        record[0] = 1; record[1] = 1;
        for (int i=2; i<n+1;++i){
            for(int j=1;j<=i;++j){
                record[i] += record[i-j]*record[j-1];
            }
        }
        return record[n];
    }

};
