class Solution {
public:
    int solve(vector<int>& prices,int index, int buy, vector<vector<int>> &dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int profit=0;
        if(buy==1){
            dp[index][buy]=max(-prices[index]+solve(prices,index+1,0,dp),solve(prices,index+1,1,dp));
        }
        else{
            dp[index][buy]=max(prices[index]+solve(prices,index+1,1,dp),solve(prices,index+1,0,dp));
        }
        return dp[index][buy];
    }
    int maxProfit(vector<int>& prices) {
        int buy=1;
        int index=0;
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,index,buy,dp);
    }
};