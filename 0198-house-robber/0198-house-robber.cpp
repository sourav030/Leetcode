class Solution {
public:
    int f(int i, vector<int> &nums, vector<int> &dp)
    {
        if(i>=nums.size()){
            return 0;
            
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        return dp[i]=max(nums[i]+ f(i+2,nums,dp),f(i+1,nums,dp));
    }
    int rob(vector<int>& nums) {
       
        // vector<int> dp(nums.size()+1,-1);
        //  return f(0,nums,dp);
           int n=nums.size();
            vector<int>dp(n+2);
            dp[n]=0;
            dp[n+1]=0;
            
            int x=n-1;
            for(int i=x;i>=0;i--)
            {
                    dp[i]=max((nums[i]+dp[i+2]),(dp[i+1]));
            }
            return dp[0];
    }
};