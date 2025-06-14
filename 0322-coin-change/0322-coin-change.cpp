class Solution {
public:
    int solve(vector<int>& coins, int n , int amount, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (n < 0 || amount < 0) return -1;
        if (dp[n][amount] != -1) return dp[n][amount];

        int ans = INT_MAX;
        int a = solve(coins, n, amount - coins[n], dp);   // include current coin
        if (a >= 0) {
            ans = min(ans, 1 + a);
        }

        int b = solve(coins, n - 1, amount, dp);          // exclude current coin
        if (b >= 0) {
            ans = min(ans, b);
        }

        return dp[n][amount] = (ans == INT_MAX) ? -1 : ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() - 1;
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return solve(coins, n, amount, dp);
    }
};
