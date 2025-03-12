class Solution {
public:
    
    int  solve(vector<vector<int>>& grid, int i, int j, int n, int m,vector<vector<int>>&dp){
        if(i>n or j>m) return 0;
        if(grid[i][j]==1) return 0;
        
        if(i==n and j==m){
            
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
       int right= solve(grid,i,j+1,n,m,dp);
       int down =solve(grid,i+1,j,n,m,dp);
       return dp[i][j]= right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(grid,0,0,n-1,m-1,dp);
         
    }
};