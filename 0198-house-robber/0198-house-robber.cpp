class Solution {
public:
    int solve(vector<int>&nums,vector<int>&dp,int index){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        return dp[index]=max(nums[index]+solve(nums,dp,index+2),solve(nums,dp,index+1));

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,dp,0);
    }
};