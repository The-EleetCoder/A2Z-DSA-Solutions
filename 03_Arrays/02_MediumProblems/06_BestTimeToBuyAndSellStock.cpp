/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

/*
Intuition:
The problem you're solving is about finding the maximum profit you can achieve by buying and selling a stock, where you can only perform one buy and one sell transaction. The goal is to determine the best days to buy and sell to maximize profit.

Key Idea:
The main idea is to keep track of the minimum price seen so far (buy), which represents the best day to buy. Then, for each subsequent price, calculate the potential profit if you were to sell on that day. If this potential profit is greater than the maximum profit seen so far, update the maximum profit.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize max profit to 0, as no profit is possible initially.
        int max_profit = 0; 
        // Start with the assumption that we buy on the first day.
        int buy = 0; 

        // Iterate over the prices starting from the second day
        for (int i = 1; i < prices.size(); i++) {

            // If the current price is lower than our current buy price, we update buy
            if (prices[i] < prices[buy]) {
                // Update the day to buy as a lower price has been found
                buy = i; 
            }

            // If selling today yields a profit, check if it's the maximum profit so far
            else if (prices[i] > prices[buy]) {
                /*
                Update max_profit with the maximum of the current max_profit 
                and the profit we would get if we sold today
                */
                max_profit = max(max_profit, prices[i] - prices[buy]);
            }
        }
        return max_profit;
    }
};
