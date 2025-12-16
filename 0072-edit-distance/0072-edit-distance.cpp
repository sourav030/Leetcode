class Solution {
public:
    vector<vector<int>> dp;

    int solve(string &word1, string &word2, int i, int j) {
        if (i < 0) return j + 1;  // insert remaining
        if (j < 0) return i + 1;  // delete remaining

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(word1, word2, i - 1, j - 1);
        }

        return dp[i][j] = 1 + min({
            solve(word1, word2, i - 1, j),     // delete
            solve(word1, word2, i, j - 1),     // insert
            solve(word1, word2, i - 1, j - 1)  // replace
        });
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        dp.assign(n1, vector<int>(n2, -1));
        return solve(word1, word2, n1 - 1, n2 - 1);
    }
};
