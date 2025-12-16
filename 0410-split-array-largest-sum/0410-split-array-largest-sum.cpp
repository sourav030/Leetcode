class Solution {
public:
    bool isValid(vector<int>& nums, int maxSum, int k) {
        int count = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > maxSum) {
                count++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for (int x : nums) high += x;

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValid(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
