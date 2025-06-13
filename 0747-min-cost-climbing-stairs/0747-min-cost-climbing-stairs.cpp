class Solution {
public:
    int solve(vector<int>&dp, vector<int>&cost, int index){
        if(index>=cost.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
       return dp[index]=min((cost[index]+solve(dp,cost,index+1)),cost[index]+solve(dp,cost,index+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        vector<int>dp2(n+1,-1);
        return min(solve(dp,cost,0),solve(dp,cost,1));
    }
};