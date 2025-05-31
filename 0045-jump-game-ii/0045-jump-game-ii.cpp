class Solution {
public:
    int solve(vector<int>&nums, int idx, vector<int>&dp){
        if(idx>=nums.size()-1) return 0;
        if(nums[idx]==0) return INT_MAX;
        if(dp[idx]!=-1) return dp[idx]; 
        int res=INT_MAX;
        for(int i=1; i<=nums[idx]; i++){
            int tem=solve(nums,idx+i, dp);
            if(tem!=INT_MAX){
                res=min(res,tem+1);
            }
        }
        return dp[idx]=res;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,0, dp);
    }
};