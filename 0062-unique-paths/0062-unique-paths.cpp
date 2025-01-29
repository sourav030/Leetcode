class Solution {
public:
    int solve(int m, int n,vector<vector<int>>& dp){
        if(m==0 and n==0) return 1;
        if(m<0 or n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int left=solve(m,n-1,dp);
        int right=solve(m-1,n,dp);
        return dp[m][n]= left+right;
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};