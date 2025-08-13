class Solution {
public:
    vector<int>dp;
    int solve(int idx, vector<int>&nums){
        if(idx>=nums.size()-1){
            return true;
        }
        if(nums[idx]==0){
            return false;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        for(int i=1; i<=nums[idx]; i++){
            if(solve(idx+i, nums)){
               return dp[idx]= true;
            }
        }
        dp[idx] =false;
        return dp[idx];
    }
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        dp.resize(nums.size()+1,-1);
        return solve(0,nums);
    }
};