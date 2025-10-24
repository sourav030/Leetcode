class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&coins, int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int mini=INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int val=solve(coins,amount-coins[i]);
            if(val!=INT_MAX){
                mini=min(mini,val+1);
            }
        }
        return dp[amount]=mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1,-1);
        int ans= solve(coins,amount);
        return ans==INT_MAX?-1:ans;
    }
};