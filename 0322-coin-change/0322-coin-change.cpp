class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&coins, int idx, int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0 or idx>=coins.size()){
            return INT_MAX;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        // take the current coint
        int take=INT_MAX;
        int sol=solve(coins,idx,amount-coins[idx]);
        if(sol!=INT_MAX){
            take=1+sol;
        }
        int nottake=solve(coins,idx+1,amount);
        return dp[idx][amount]= min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.assign(n+1,vector<int>(amount+1,-1));
        int  idx=0;
        int ans= solve(coins,idx,amount);
        return ans==INT_MAX?-1:ans;
    }
};