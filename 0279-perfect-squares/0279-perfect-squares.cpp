class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int result=INT_MAX;
        for(int i=1; i*i<=n; i++){
            int ans=1+solve(n-i*i,dp);
            result=min(ans,result);
        }
        return dp[n]=result;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};