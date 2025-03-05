class Solution {
public:
    
    int solve(int index,int amount,vector<int>& coins,vector<vector<int>>&dp){
        if(amount==0){
            return 1;
        }
         if(index>=coins.size() or amount<0){
            return 0;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int include=solve(index,amount-coins[index],coins,dp);
        int exclude=solve(index+1,amount,coins,dp);
        return dp[index][amount]= include + exclude;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};