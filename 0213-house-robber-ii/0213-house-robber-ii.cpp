class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums, int idx, int end) {
        if (idx > end) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }

        int choriKiya = nums[idx] + solve(nums, idx + 2, end);
        int nhiChoriKiya = solve(nums, idx + 1, end);

        return dp[idx] = max(choriKiya, nhiChoriKiya);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        
        dp.assign(n, -1);
        int case1 = solve(nums, 0, n - 2);

       
        dp.assign(n, -1);
        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};
