class Solution {
public:

   int solve(int index, vector<int>& prices, int buy, int cap, vector<vector<vector<int>>> &dp) {
        if (index >= prices.size() || cap == 0) return 0;  // Base case

        if (dp[index][buy][cap] != -1) return dp[index][buy][cap];  // Memoization

        int profit = 0;
        if (buy) {
            // Choice: Buy or Skip
            profit = max(-prices[index] + solve(index+1, prices, 0, cap, dp),
                         solve(index+1, prices, 1, cap, dp));
        } else {
            // Choice: Sell or Hold
            profit = max(prices[index] + solve(index+1, prices, 1, cap-1, dp),
                         solve(index+1, prices, 0, cap, dp));
        }

        return dp[index][buy][cap] = profit;  // Store result in DP table
    }

    int maxProfit(int k, vector<int>& prices) {
         int N = prices.size();  // Define N correctly
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(2, vector<int>(k+1, -1)));  // Initialize DP table
        return solve(0, prices, 1, k, dp);
    }
};