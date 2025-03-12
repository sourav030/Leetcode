class Solution {
public:
    long long solve(vector<vector<int>>& grid, int i, int j, int n,int m, vector<vector<long long>>&dp){
        if(i>n or j>m) return INT_MAX;
        if(i==n and j==m) return grid[n][m];
        if(dp[i][j]!=-1) return dp[i][j];
        long long right=grid[i][j]+solve(grid,i,j+1,n,m,dp);
        long long down=grid[i][j]+solve(grid,i+1,j,n,m,dp);
        return dp[i][j]= min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));
        return solve(grid,0,0,n-1,m-1,dp);
    }
};