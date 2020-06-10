class StockSpanner {
public:
    vector<int> span;
    vector<int> hist;
    StockSpanner()
    {

    }

    int next(int price)
    {
        hist.push_back(price);
        if (hist.size()==1) {
            span.push_back(1);
            return 1;
        }

        int result = 1;
        int idx = hist.size()-2;
        while (idx>=0) {
            if (hist[idx] > price) {
                break;
            }
            else {
                result += (span[idx]);
                idx -= span[idx];
            }
        }
        span.push_back(result);
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
