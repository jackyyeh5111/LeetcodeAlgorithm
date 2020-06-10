// Time: 29.46% 
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries)
    {
        vector<int> result;
        int sum=0;
        for (int a : A) {
            if (a%2==0) sum+=a;
        }
        for (vector<int> query : queries){
            if(query[0]%2==0 && A[query[1]]%2==0) sum += query[0];
            else if (query[0]%2!=0 && A[query[1]]%2==0) sum -= A[query[1]];
            else if (query[0]%2!=0 && A[query[1]]%2!=0) sum += (query[0]+A[query[1]]);

            A[query[1]] += query[0];
            result.push_back(sum);
        }
        return result;
    }
};
