class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        vector<int> buy(prices.size()), sell(prices.size());
        buy[0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
		    sell[i] = max(buy[i - 1] + prices[i], sell[i - 1] - prices[i - 1] + prices[i]);
            if (ret < sell[i]) ret = sell[i];
            if (1 == i) buy[i] = buy[0] + prices[0] - prices[1];
            else buy[i] = max(sell[i - 2] - prices[i], buy[i - 1] + prices[i - 1] - prices[i]);
        }
        return ret;
    }
};
