class Solution {
public:
    int search(vector<int>& nums, int target) {
    int st = 0;
    int end = nums.size() - 1;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        // Check if the left half is sorted
        if (nums[st] <= nums[mid]) {
            if (nums[st] <= target && target < nums[mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        // Otherwise, the right half must be sorted
        else {
            if (nums[mid] < target && target <= nums[end]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1; // Target not found
}

};