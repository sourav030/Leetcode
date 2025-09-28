class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&nums, int idx , int n){
        if(idx>=n-1){
            return 0;
        }
        if(nums[idx]==0){
            return INT_MAX;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int jump=INT_MAX;
        for(int i=1; i<=nums[idx]; i++){
            int val=solve(nums, idx+i,n);
            if(val!=INT_MAX){
                jump=min(jump,val+1);
            }
        }
        return dp[idx]=jump;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        dp.resize(n+1,-1);
        return solve(nums, 0, n);
    }
};