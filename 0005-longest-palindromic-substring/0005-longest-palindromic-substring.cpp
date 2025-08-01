class Solution {
public:
    int check(string &s, int i, int j, vector<vector<int>>& dp) {
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = check(s, i+1, j-1, dp);
        return dp[i][j] = 0;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int start = 0, len = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                if(check(s, i, j, dp)) {
                    if(j - i + 1 > len) {
                        len = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, len);
    }
};
