class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX, maxprofit = 0, len = prices.size();
        for (int i = 0; i < len; i++) {
            minprice = min(prices[i], minprice);
            maxprofit = max(prices[i] - minprice, maxprofit);
        }
        return maxprofit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxn = 0;
        int minp = prices[0];
        int len = prices.size();
        for(int i = 0; i < len; i++){
            if(prices[i] <= minp)
                minp = prices[i];
            maxn = max(maxn, prices[i] - minp);
        }
        return maxn;
    }
};
