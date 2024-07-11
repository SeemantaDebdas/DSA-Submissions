class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int profit = 0;

        int i = 0, j = 1;

        while(j < prices.size())
        {
            if(prices[i] > prices[j])
            {
                i = j;
                j++;
                continue;
            }

            profit = prices[j] - prices[i];
            maxProfit = max(maxProfit, profit);
            j++;
        }

        return maxProfit;
    }
};