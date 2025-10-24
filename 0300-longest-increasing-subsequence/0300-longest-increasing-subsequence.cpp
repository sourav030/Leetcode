class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int index, int prev) {
        if (index >= nums.size()) {
            return 0;
        }

        // Shift prev by +1 to avoid using -1 as an index
        if (dp[index][prev + 1] != -1) {
            return dp[index][prev + 1];
        }

        int take = INT_MIN;
        if (prev == -1 || nums[index] > nums[prev]) {
            take = 1 + solve(nums, index + 1, index);
        }

        int nottake = solve(nums, index + 1, prev);

        return dp[index][prev + 1] = max(take, nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n + 1, -1));  // +1 for the case prev = -1
        return solve(nums, 0, -1);
    }
};
