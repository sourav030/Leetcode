class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        // Step 1: Compute prefix sums
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        vector<int> ans;
        // Step 2: Binary search for each query
        for (int q : queries) {
            int l = 0, r = prefix.size();  // search range
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (prefix[mid] <= q) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            ans.push_back(l); // 'l' is the count of elements whose sum <= q
        }
        return ans;
    }
};
