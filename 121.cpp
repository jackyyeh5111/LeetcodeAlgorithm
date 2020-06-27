/************ Stack T:O(n),S:O(n) *************/
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        stack<int> s;
        int ans=0;
        for (int price:prices) {
            if(s.empty()||s.top()>price) s.push(price);
            else ans=max(ans,price-s.top());
        }
        return ans;
    }
};

/************ Simplify stack T:O(n),S:O(1) *************/
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int localMin=INT_MAX;
        int ans=0;
        for (int price:prices) {
            localMin=min(localMin,price);
            ans=max(ans,price-localMin);
        }
        return ans;
    }
};
