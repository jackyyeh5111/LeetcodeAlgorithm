/*
    [-,-,-,-,5], k=2
             ^
     12345 23451
     3451 4513
     513 135
     35 53
     3
     Apply queue for easily removing number from the circle.
     T:O(kn)
*/
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i=0; i<n; ++i) q.push(i+1);
        for (int i=0; i<n-1; ++i) {
            for (int j=0; j<k-1; ++j) {
                q.push(q.front()); q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};
