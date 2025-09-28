class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&nums, int idx, int n){
        if(idx>=n-1){
            return 1;
        }
        if(nums[idx]==0){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        for(int i=1; i<=nums[idx]; i++){
            if(solve(nums, idx+i,n)){
                return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        int idx=0;
        return solve(nums,idx,n);
    }
};