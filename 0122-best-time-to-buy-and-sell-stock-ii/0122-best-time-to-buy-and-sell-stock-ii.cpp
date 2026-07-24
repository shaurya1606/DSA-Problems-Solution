class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadBuy = 0, aheadNotBuy = 0, curBuy = 0, curNotBuy = 0;

        for (int day = n - 1; day >= 0; day--) {
            curNotBuy = max(prices[day] + aheadBuy, 0 + aheadNotBuy);
            curBuy = max(-prices[day] + aheadNotBuy, 0 + aheadBuy);
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};