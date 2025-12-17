class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&nums, int idx){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int choriKiya=nums[idx]+solve(nums,idx+2);
        int nhiChoriKiya=solve(nums,idx+1);
        return dp[idx]=max(choriKiya,nhiChoriKiya);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        return solve(nums,0);

    }
};