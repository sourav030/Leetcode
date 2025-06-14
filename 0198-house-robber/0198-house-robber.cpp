class Solution {
public:
    int solve(vector<int>&nums, int idx,vector<int>&dp){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        return dp[idx]= max(nums[idx]+solve(nums,idx+2,dp),solve(nums,idx+1,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,0,dp);
    }
};