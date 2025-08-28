class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window; // use long long to avoid overflow

        for(int i = 0; i < nums.size(); i++) {
            // Check if there is any number in window within [nums[i]-valueDiff, nums[i]+valueDiff]
            auto it = window.lower_bound((long long)nums[i] - valueDiff);
            if(it != window.end() && *it <= (long long)nums[i] + valueDiff)
                return true;

            window.insert(nums[i]);

            // Maintain sliding window of size indexDiff
            if(window.size() > indexDiff)
                window.erase(nums[i - indexDiff]);
        }

        return false;
    }
};
