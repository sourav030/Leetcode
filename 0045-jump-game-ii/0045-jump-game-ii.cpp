class Solution {
public:
    vector<int>dp;
    int solve(int idx, vector<int>&nums){
        if(idx>=nums.size()-1){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        if(nums[idx]==0){
            return INT_MAX;
        }
        int mini=INT_MAX;
        for(int i=1; i<=nums[idx]; i++){
            int val=solve(idx+i, nums );
            if(val!=INT_MAX){
                mini=min(mini,val+1);
            }
        }
        return dp[idx]=mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        return solve(0,nums);
    }
};