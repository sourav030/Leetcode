class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums, int target, int n){
        if(target==0){
            return 1;
        }
        
        if(n<0 or target<0){
            return 0;
        }

        if(dp[n][target]!=-1){
            return dp[n][target];
        }

        return dp[n][target]=solve(nums,target-nums[n],n-1) || solve(nums,target,n-1);


    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(auto ele:nums){
            sum+=ele;
        }
         dp.assign(n+1,vector<int>(sum+1,-1));
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        return solve(nums,target,nums.size()-1);

    }
};