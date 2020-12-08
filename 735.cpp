/*
    stack approach
    We directly accept all positive number into our stack, which means we dont need to check while asteroid goes right. Once we meet nengative incoming number, there would be collision and need to be checked which one is exploded.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        stack<int> s;
        for(int asteroid:asteroids) {
            if (asteroid>0) {
                s.push(asteroid);
                continue;
            }
            bool destroy=0;
            while(!s.empty()&&s.top()>0) {
                int l=s.top();
                if (l>=abs(asteroid)) {
                    if (l==abs(asteroid)) s.pop();
                    destroy=1;
                    break;
                }
                else s.pop();
            }
            if (!destroy) s.push(asteroid);
        }
        vector<int> ans;
        while(!s.empty()) {
            ans.insert(ans.begin(),s.top());
            s.pop();
        }
        return ans;

    }
};
