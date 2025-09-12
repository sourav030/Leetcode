class Solution {
public:
    int row, col;
    vector<vector<int>> dp;

    int solve(int r, int c) {
        if (r == row - 1 && c == col - 1) return 1; // reached destination
        if (r >= row || c >= col) return 0;         // out of bounds

        if (dp[r][c] != -1) return dp[r][c];        // already computed

        int right = solve(r, c + 1);
        int down = solve(r + 1, c);

        return dp[r][c] = right + down;
    }

    int uniquePaths(int m, int n) {
        row = m;
        col = n;
        dp.assign(m, vector<int>(n, -1)); 
        return solve(0, 0);
    }
};
