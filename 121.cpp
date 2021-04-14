/***** Fifth Visit *****/
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int buy=INT_MAX,sell=INT_MIN;
        for (int p:prices) {
            buy=min(buy,p);
            sell=max(sell,p-buy);
        }
        return sell;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size()<2) return 0;
        int ans=0,cmin=prices[0];
        for (int i=1; i<prices.size(); ++i) {
            ans=max(ans,prices[i]-cmin);
            cmin=min(cmin,prices[i]);
        }
        return ans;
    }
};

/***** Fourth Visit *****/
/*
    brute force: enumerate all pair and find max profit.
    T:O(n^2)/S:O(1)
    -----
    array -> running ptr with a moving window.
    for each position, find the minimum price so far,
    then its the best profit we can get if we sold at the current price.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        if (n<=1) return 0;
        int low=prices[0],ans=0;
        for (int i=1; i<n; ++i) {
            ans=max(ans,prices[i]-low);
            low=min(low,prices[i]);
        }
        return ans;
    }
};

/***** Thrid Visit *****/
/*
    Only one transaction is accepted.
    buy cheapest / sell the most expencive
    -----
    brute force:
    enumerate each pair then find max profit
    T:O(n^2)/S:O(1)
    -----
    Array -> 2 ptr solution, say i, j.
    i denotes min price so far, and j denotes incoming price.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size()<=1) return 0;
        int pmin=prices[0],ans=0,n=prices.size();
        for (int i=1; i<n; ++i) {
            ans=max(ans,prices[i]-pmin);
            pmin=min(pmin,prices[i]);
        }
        return ans;
    }
};

/***** Second Visit *****/
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        /*
            brute force: O(n^2), S:O(n)
            --------------------
            max profit -> buy in local min and sale in local max.
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

/***** First Visit *****/
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
