class Solution {
public:
    vector<vector<int>> dp;

    int solve(string& word1, string& word2, int i, int j) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = 1 + solve(word1, word2, i - 1, j - 1);
        else
            return dp[i][j] = max(solve(word1, word2, i - 1, j), solve(word1, word2, i, j - 1));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        dp.assign(n, vector<int>(m, -1));

        int lcsLen = solve(word1, word2, n - 1, m - 1);
        return (n - lcsLen) + (m - lcsLen);
    }
};
