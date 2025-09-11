class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[end]) {
                // minimum must be in the right half
                start = mid + 1;
            } else {
                // minimum is at mid or in the left half
                end = mid;
            }
        }
        return nums[start]; // or nums[end], since start == end
    }
};
