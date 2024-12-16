class Solution {
public:
    int solve(int day, int trans, int buy, int n, vector<int>& prices, vector<vector<vector<int>>>& dp) {
    if (day == n || trans == 0) {
        return 0;
    }
    if (dp[day][trans][buy] != -1) {
        return dp[day][trans][buy];
    }

    if (buy) {
        return dp[day][trans][buy] = max(-prices[day] + solve(day + 1, trans, 0, n, prices, dp), 
                                         solve(day + 1, trans, 1, n, prices, dp));
    } else {
        return dp[day][trans][buy] = max(prices[day] + solve(day + 1, trans - 1, 1, n, prices, dp), 
                                         solve(day + 1, trans, 0, n, prices, dp));
    }
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));  // 3 transactions max, buy/sell state
    return solve(0, 2, 1, n, prices, dp);
}

  
};