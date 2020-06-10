class StockSpanner {
public:
    stack<int> hist, span;
    StockSpanner()
    {

    }

    int next(int price)
    {
        int result = 1;
        while (!hist.empty() && hist.top() <= price) {
            result += span.top(); span.pop();
            hist.pop();
        }
        hist.push(price);
        span.push(result);
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
