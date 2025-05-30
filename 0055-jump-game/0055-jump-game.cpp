class Solution {
public:
    bool solve(vector<int>&nums, int idx, vector<int>&dp){
        if(idx>=nums.size()-1) return true;
        if(dp[idx]!=-1) return dp[idx];
        if(nums[idx]==0) return false;
        for(int i=1; i<=nums[idx]; i++){
            if(solve(nums,idx+i,dp)){
                return dp[idx]=1;
            }
        }
        return dp[idx]= 0;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        if(nums.size()==1) return 1;
        if(nums[0]==0) return 0;
        int idx=0;
       return solve(nums,idx,dp);
    }
};