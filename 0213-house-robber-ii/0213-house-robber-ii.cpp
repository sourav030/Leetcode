class Solution {
        int solve(vector<int> nums, int idx, int n, vector<int>&dp)
        {
                
                if(idx >n)
                {
                        return 0;
                }
                if(dp[idx]!=-1)
                {
                        return dp[idx];
                }
                dp[idx]=max(nums[idx]+solve(nums,idx+2,n,dp),solve(nums,idx+1,n,dp));
                return dp[idx];
        }
public:
    int rob(vector<int>& nums) {
        
            int n=nums.size();
            if(n==1)
            {
                    return nums[0];
            }
            vector<int>dp1(n+2,-1);
            vector<int>dp2(n+2,-1);
            
            return max(solve(nums,0,n-2,dp1),solve(nums,1,n-1,dp2));
            
            
            
            
    }
};