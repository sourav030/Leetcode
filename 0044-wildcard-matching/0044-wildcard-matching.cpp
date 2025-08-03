class Solution {
public:
    // dp[i][j] will be -1 if not calculated, 0 = false, 1 = true
    int dp[2001][2001];

    bool solve(string& s, string& p, int n1, int n2) {
        if (n1 < 0 && n2 < 0) return true;
        if (n2 < 0) return false;
        if (n1 < 0) {
            for (int j = 0; j <= n2; j++) {
                if (p[j] != '*') return false;
            }
            return true;
        }

        if (dp[n1][n2] != -1) return dp[n1][n2];

        bool res = false;
        if (s[n1] == p[n2] || p[n2] == '?') {
            res = solve(s, p, n1 - 1, n2 - 1);
        }
        else if (p[n2] == '*') {
            res = solve(s, p, n1 - 1, n2) || solve(s, p, n1, n2 - 1);
        }
        else {
            res = false;
        }

        return dp[n1][n2] = res;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(s, p, s.size() - 1, p.size() - 1);
    }
};
