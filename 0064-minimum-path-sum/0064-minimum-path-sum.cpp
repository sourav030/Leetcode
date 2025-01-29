class Solution {
public:
    int solve(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (n == 0 && m == 0) return grid[0][0];  // Base Case
        if (n < 0 || m < 0) return INT_MAX;  // Out-of-bounds case

        if (dp[n][m] != -1) return dp[n][m];  // Memoization check

        int left = solve(n, m - 1, grid, dp);
        int top = solve(n - 1, m, grid, dp);

        return dp[n][m] = grid[n][m] + min(left, top);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, grid, dp);
    }
};
