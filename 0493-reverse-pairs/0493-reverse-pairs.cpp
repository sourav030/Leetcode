class Solution {
public:
    int count = 0;

    void merge(vector<int>& nums, int start, int mid, int end) {
        int j = mid + 1;

        
        for (int i = start; i <= mid; i++) {
            while (j <= end && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

       
        vector<int> temp;
        int left = start, right = mid + 1;

        while (left <= mid && right <= end) {
            if (nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }

        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= end) temp.push_back(nums[right++]);

        for (int i = start; i <= end; i++) {
            nums[i] = temp[i - start];
        }
    }

    void solve(vector<int>& nums, int start, int end) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;
        solve(nums, start, mid);
        solve(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }

    int reversePairs(vector<int>& nums) {
        solve(nums, 0, nums.size() - 1);
        return count;
    }
};
