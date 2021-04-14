/*
    stock trading system

    buy: max heap
    sell: min heap

    T:O(logn)/S:O(n)
*/
typedef pair<int,int> pii;
class Solution {
public:
    priority_queue<pii,vector<pii>,greater<pii>> sell;
    priority_queue<pii,vector<pii>,less<pii>> buy;
    int mod=1e9+7;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders)
    {
        for (auto &order:orders) {
            int price=order[0], amount=order[1], type=order[2];
            if (type==0) { // buy
                while (amount>0&&!sell.empty()&&sell.top().first<=price) {
                    auto t=sell.top(); sell.pop();
                    if (t.second>amount) sell.push({t.first,t.second-amount});
                    amount-=t.second;
                }
                if (amount>0&&!buy.empty()&&buy.top().first==price) {
                    auto t=buy.top(); buy.pop();
                    buy.push({t.first,t.second+amount});
                }
                else if (amount>0) buy.push({price,amount});
            }
            else {
                while (amount>0&&!buy.empty()&&buy.top().first>=price) {
                    auto t=buy.top(); buy.pop();
                    if (t.second>amount) buy.push({t.first,t.second-amount});
                    amount-=t.second;
                }
                if (amount>0&&!sell.empty()&&sell.top().first==price) {
                    auto t=sell.top(); sell.pop();
                    sell.push({t.first,t.second+amount});
                }
                else if (amount>0) sell.push({price,amount});
            }
        }
        int ans=0;
        while (!buy.empty()) {
            ans=(ans+(buy.top().second%mod))%mod;
            buy.pop();
        }
        while (!sell.empty()) {
            ans=(ans+(sell.top().second%mod))%mod;
            sell.pop();
        }
        return ans;
    }
};
