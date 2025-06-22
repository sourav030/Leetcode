class Solution {
public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        sort(arr.begin(), arr.end());

        // Memoization table: dp[idx][prev+1] stores vector for that state
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1));

        return solve(0, -1, arr, dp);
    }

private:
    vector<int> solve(int idx, int prevIdx, vector<int>& arr, vector<vector<vector<int>>>& dp) {
        if (idx == arr.size()) return {};

        // Memoization hit
        if (!dp[idx][prevIdx + 1].empty()) {
            return dp[idx][prevIdx + 1];
        }

        // Exclude current element
        vector<int> excl = solve(idx + 1, prevIdx, arr, dp);

        vector<int> incl;
        // Include current element if it's divisible
        if (prevIdx == -1 || arr[idx] % arr[prevIdx] == 0) {
            incl = solve(idx + 1, idx, arr, dp);
            incl.insert(incl.begin(), arr[idx]);
        }

        // Choose the larger subset
        if (incl.size() > excl.size()) {
            dp[idx][prevIdx + 1] = incl;
        } else {
            dp[idx][prevIdx + 1] = excl;
        }

        return dp[idx][prevIdx + 1];
    }
};
