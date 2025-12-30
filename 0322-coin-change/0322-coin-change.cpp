class Solution {
public:
    vector<vector<int>>dp;

    int solve(vector<int>& coins, int idx, int amount, long long sum) {
    if (sum == amount) return 0;
    if (idx >= coins.size() || sum > amount) return INT_MAX;

    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    int take = INT_MAX;
    if (sum + coins[idx] <= amount) {
        take = solve(coins, idx, amount, sum + coins[idx]);
        if (take != INT_MAX) take += 1;
    }

    int nottake = solve(coins, idx + 1, amount, sum);

    return dp[idx][sum] = min(take, nottake);
}

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int idx=0;
        dp.assign(n+1,vector<int>(amount+1,-1));
        int ans= solve(coins,idx,amount, 0);
        return ans==INT_MAX?-1:ans;
    }
};