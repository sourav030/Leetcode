class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& arr, int index, int n, int k) {
        if (k == 0) {
            ans.push_back(arr);  // store the current combination
            return;
        }
        if (index > n) {
            return;
        }

        // Choose current number
        arr.push_back(index);
        solve(arr, index + 1, n, k - 1);
        arr.pop_back();

        // Skip current number
        solve(arr, index + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        solve(nums, 1, n, k);
        return ans;
    }
};
