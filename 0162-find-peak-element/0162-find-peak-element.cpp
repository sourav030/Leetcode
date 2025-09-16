class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Handle boundaries safely
            long left = (mid - 1 >= 0) ? nums[mid - 1] : LONG_MIN;
            long right = (mid + 1 < n) ? nums[mid + 1] : LONG_MIN;

            if (nums[mid] > left && nums[mid] > right) {
                return mid; // Found peak
            }

            if (nums[mid] < right) {
                start = mid + 1; // Peak must be on right side
            } else {
                end = mid - 1; // Peak must be on left side
            }
        }
        return -1; // Should never reach here
    }
};
