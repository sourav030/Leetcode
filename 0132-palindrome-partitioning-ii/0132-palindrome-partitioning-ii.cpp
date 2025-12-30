class Solution {
public:
    vector<int> dp;

    bool palindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int solve(string &s, int idx) {
        if (idx == s.length()) return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int ans = INT_MAX;

        for (int i = idx; i < s.length(); i++) {
            if (palindrome(s, idx, i)) {
                int cuts = 1 + solve(s, i + 1);
                ans = min(ans, cuts);
            }
        }

        return dp[idx] = ans;
    }

    int minCut(string s) {
        int n = s.length();
        dp.assign(n, -1);

        
        return solve(s, 0) - 1;
    }
};
