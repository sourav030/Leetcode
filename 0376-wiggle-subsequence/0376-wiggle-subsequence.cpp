class Solution {
public:
    int solve(vector<int>& nums, int idx, bool isUp, vector<vector<int>>& dp) {
        if (idx == nums.size()) return 0;
        if (dp[idx][isUp] != -1) return dp[idx][isUp];

        int maxLen = 0;
        for (int next = idx + 1; next < nums.size(); ++next) {
            if (isUp && nums[next] > nums[idx]) {
                maxLen = max(maxLen, 1 + solve(nums, next, !isUp, dp));
            }
            if (!isUp && nums[next] < nums[idx]) {
                maxLen = max(maxLen, 1 + solve(nums, next, !isUp, dp));
            }
        }

        return dp[idx][isUp] = maxLen;
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return 1 + max(solve(nums, 0, true, dp), solve(nums, 0, false, dp));
    }
};
