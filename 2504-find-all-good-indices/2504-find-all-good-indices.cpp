class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nonInc(n, 1), nonDec(n, 1);

        // Build non-increasing prefix
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                nonInc[i] = nonInc[i - 1] + 1;
            } else {
                nonInc[i] = 1;
            }
        }

        // Build non-decreasing suffix
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                nonDec[i] = nonDec[i + 1] + 1;
            } else {
                nonDec[i] = 1;
            }
        }

        vector<int> ans;
        for (int i = k; i < n - k; i++) {
            if (nonInc[i - 1] >= k && nonDec[i + 1] >= k) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
