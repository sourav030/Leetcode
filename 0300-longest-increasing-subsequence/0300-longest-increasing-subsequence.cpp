class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int idx, int prev) {
        if (idx == nums.size()) return 0;

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int take = 0;
        if (prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + solve(nums, idx + 1, idx);
        }

        int notTake = solve(nums, idx + 1, prev);

        return dp[idx][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n + 1, -1));
        return solve(nums, 0, -1);
    }
};
