class Solution {
public:
    long long solve(vector<vector<int>>& grid,  int n,int m, vector<vector<long long>>&dp){
        if(n<0 or m<0) return INT_MAX;
        if(n==0 and m==0) return grid[n][m];
        if(dp[n][m]!=-1) return dp[n][m];
        long long right=solve(grid,n,m-1,dp);
        long long down=solve(grid,n-1,m,dp);
        return dp[n][m]= grid[n][m]+ min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));
        return solve(grid,n-1,m-1,dp);
    }
};