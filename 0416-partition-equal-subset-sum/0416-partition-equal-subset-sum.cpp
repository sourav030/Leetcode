class Solution {
public:
    bool solve(vector<int>&arr,int target,int n, vector<vector<int>>&dp){
        if(target==0){
            return true;
        }
        if(n<=0 or target<0){
            return false;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        if(arr[n-1]>target){
            dp[n][target]=solve(arr,target,n-1,dp);
        }
        else{
            dp[n][target]=solve(arr,target-arr[n-1],n-1,dp)||solve(arr,target,n-1,dp);
        }
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        return solve(nums,sum/2,nums.size(),dp);
    }
};