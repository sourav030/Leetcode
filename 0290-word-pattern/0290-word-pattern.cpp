class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;
        string word = "";

        // Split string s into words
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (!word.empty()) {
                    vec.push_back(word);
                    word = "";
                }
            }
        }
        if (!word.empty()) vec.push_back(word); // push last word

        if (vec.size() != pattern.size()) return false;

        unordered_map<char, string> mp;
        unordered_set<string> used;

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string w = vec[i];

            if (mp.count(ch)) {
                if (mp[ch] != w) return false;
            } else {
                if (used.count(w)) return false;
                mp[ch] = w;
                used.insert(w);
            }
        }
        return true;
    }
};
