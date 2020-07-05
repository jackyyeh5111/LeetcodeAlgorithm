/************ Second Visit ************/
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        /*
            brute force: O(n^2), S:O(n)
            --------------------
            max profit -> buy in local min and sale in local max.
            Use
            use 2 ptr. 1 ptr to record min value so far
            the other ptr traverse each value.
            T:O(n),S:O(1)
        */
        int ans=0;
        if (prices.size()==0) return ans;
        int localMin=prices[0];
        for (int i=1; i<prices.size(); ++i) {
            if (prices[i]<localMin) localMin=prices[i];
            ans=max(ans,prices[i]-localMin);
        }
        return ans;
    }
};

/************ First Visit ************/
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
