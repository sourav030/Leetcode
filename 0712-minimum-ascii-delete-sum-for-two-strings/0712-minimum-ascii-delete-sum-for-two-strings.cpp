class Solution {
public:
    vector<vector<int>> dp;

    int solve(string& s1, string& s2, int idx1, int idx2) {
        if (idx1 >= s1.length()) {
            int sum = 0;
            for (int i = idx2; i < s2.length(); i++) {
                sum += s2[i];
            }
            return sum;
        }
        if (idx2 >= s2.length()) {
            int sum = 0;
            for (int i = idx1; i < s1.length(); i++) {
                sum += s1[i];
            }
            return sum;
        }

        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        if (s1[idx1] == s2[idx2]) {
            return dp[idx1][idx2] = solve(s1, s2, idx1 + 1, idx2 + 1);
        }

        int deleteFromS1 = s1[idx1] + solve(s1, s2, idx1 + 1, idx2);
        int deleteFromS2 = s2[idx2] + solve(s1, s2, idx1, idx2 + 1);

        return dp[idx1][idx2] = min(deleteFromS1, deleteFromS2);
    }

    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        dp.resize(n1 + 1, vector<int>(n2 + 1, -1));
        return solve(s1, s2, 0, 0);
    }
};
