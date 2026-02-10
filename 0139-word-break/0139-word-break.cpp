class Solution {
public:
    unordered_map<string, int> mp;
    unordered_map<int, bool> dp;   
    int n;

    bool solve(string &str, int idx) {

        if (idx >= n)
            return true;

        if (dp.count(idx))
            return dp[idx];

        string word = "";

        for (int i = idx; i < n; i++) {      
            word += str[i];

            if (mp.find(word) != mp.end() &&
                solve(str, i + 1)) {

                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        for (auto &w : wordDict)
            mp[w]++;

        n = s.length();

        return solve(s, 0);
    }
};
