class Solution {
public:
    int solve(vector<int>&prices,int index,  vector<vector<int>>&dp,int canBuy){
        if(index>=prices.size()) return 0;
        if(dp[index][canBuy]!=-1){
            return dp[index][canBuy];
        }
        if(canBuy){
            dp[index][canBuy]=max(-prices[index]+solve(prices,index+1,dp,0),
            solve(prices,index+1,dp,1));
        }
        else{
            dp[index][canBuy]=max(prices[index]+solve(prices,index+2,dp,1),
            solve(prices,index+1,dp,0));
        }
        return dp[index][canBuy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,dp,1);
    }
};