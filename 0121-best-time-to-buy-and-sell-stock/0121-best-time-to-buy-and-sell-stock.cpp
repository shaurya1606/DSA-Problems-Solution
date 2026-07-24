class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProffit = 0;
        int buyDay = 0;
        int currProffit = 0;
        int noOfDay = prices.size();

        for(int day = 1; day < noOfDay; day++) {
            if(prices[day] < prices[buyDay]) {
                buyDay = day;
                continue;
            }
            currProffit = prices[day] - prices[buyDay];
            maxProffit = max(currProffit, maxProffit);
        }

        return maxProffit;
    }
};