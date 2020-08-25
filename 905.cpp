/*
    sort with customize compare
    T:O(nlogn)/S:O(1)
    ---------
    use another cache to save even/odd during iteration
    T:O(n)/S:O(n)
    ---------
    group the array with even first then odd.
    use 2 ptr method
    2 4 3 1
      ^
          ^
    T:O(n)/S:O(1)
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A)
    {
        int l=0, n=A.size();
        for (int i=0; i<n; ++i) {
            if (A[i]%2==0) swap(A[l++],A[i]);
        }
        return A;
    }
};

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A)
    {
        sort(A.begin(),A.end(),[](int a, int b){
            return (a%2)<(b%2);
        });
        return A;
    }
};
