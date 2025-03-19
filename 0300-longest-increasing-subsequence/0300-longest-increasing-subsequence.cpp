class Solution {
public:
    int solve(vector<int>&nums,int index, int n, int prev, vector<vector<int>>&dp){
        if(index>=n)return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int take=0;
        int notTake=0;
        if(prev==-1 or nums[index]>nums[prev]){
            take=1+solve(nums,index+1,n,index,dp);
        }
        notTake=0+solve(nums,index+1,n,prev,dp);
        return dp[index][prev+1]= max(notTake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,0,n,-1,dp);

    }
};