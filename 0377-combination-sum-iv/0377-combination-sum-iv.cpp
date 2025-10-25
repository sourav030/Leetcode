class Solution {
public:
    int solve(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) return 1;  // one valid combination
        if (target < 0) return 0;   // invalid combination
        
        if (dp[target] != -1) return dp[target];
        
        long long count = 0;
        for (int num : nums) {
            count += solve(nums, target - num, dp);
        }
        
        return dp[target] = count;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};
