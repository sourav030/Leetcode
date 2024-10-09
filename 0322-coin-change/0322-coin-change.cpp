class Solution {
    int find(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // Base case: if amount is 0, we need 0 coins
        if (amount == 0) return 0;
        
        // Base case: if amount is negative or no coins are left, return a large value (impossible case)
        if (amount < 0 || index <= 0) return INT_MAX;
        
        // If result is already computed, return the stored result
        if (dp[index][amount] != -1) return dp[index][amount];
        
        // Recursive case: either take the current coin or skip it
        int take = INT_MAX;
        if (amount >= coins[index - 1]) {
            int res = find(index, amount - coins[index - 1], coins, dp);
            if (res != INT_MAX) {
                take = res + 1;  // Add one coin if we take the current one
            }
        }
        int skip = find(index - 1, amount, coins, dp);
        
        // Store the result in dp array and return the minimum of both choices
        return dp[index][amount] = min(take, skip);
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp array to store results, initialized to -1
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        
        int result = find(n, amount, coins, dp);
        
        // If result is INT_MAX, it means the amount can't be made up with the coins
        return (result == INT_MAX) ? -1 : result;
    }
};
