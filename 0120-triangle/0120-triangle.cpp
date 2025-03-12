class Solution {
public:
    int solve(vector<vector<int>>&triangle,int i,int j,int m,vector<vector<int>>&dp ){
        if(i>=m) return 0;
        if(i==m-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int take=solve(triangle,i+1,j,m,dp);
        int nontake=solve(triangle,i+1,j+1,m,dp);
        return dp[i][j]= triangle[i][j]+min(take,nontake);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return solve(triangle,0,0,m,dp);
    }
};