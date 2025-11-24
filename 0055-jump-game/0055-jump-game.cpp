class Solution {
public:
    vector<int>dp;
    int solve(int idx, vector<int>&nums){
        if(idx>=nums.size()-1){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        if(nums[idx]==0){
            return false;
        }
        for(int i=1; i<=nums[idx]; i++){
            if(solve(idx+i,nums)){
                return dp[idx]= 1;
            }
        }
        return dp[idx]=0;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]==0 and n==1){
            return true;
        }
        dp.resize(n+1,-1);
        return solve(0,nums);
    }
};