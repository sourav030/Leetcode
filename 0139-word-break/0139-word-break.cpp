class Solution {
public:
    unordered_set<string> dict; // store wordDict
    vector<int> memo; // -1 = not computed, 0 = false, 1 = true
    
    bool solve(int idx, const string &s) {
        if (idx == s.length()) return true;
        if (memo[idx] != -1) return memo[idx];
        
        for (int end = idx; end < s.length(); end++) {
            string word = s.substr(idx, end - idx + 1);
            if (dict.count(word) && solve(end + 1, s)) {
                return memo[idx] = true;
            }
        }
        
        return memo[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        dict.clear();
        for (auto &w : wordDict) dict.insert(w);
        memo.assign(s.length(), -1);
        return solve(0, s);
    }
};
