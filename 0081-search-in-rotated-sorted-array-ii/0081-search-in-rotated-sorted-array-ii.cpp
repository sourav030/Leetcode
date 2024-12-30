class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2; // Overflow safe calculation

            // Target found
            if (nums[mid] == target) return true;

            // Handle duplicates
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
            }
            // Left half is sorted
            else if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1; // Search in the left half
                } else {
                    start = mid + 1; // Search in the right half
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1; // Search in the right half
                } else {
                    end = mid - 1; // Search in the left half
                }
            }
        }

        return false; // Target not found
    }
};
