class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mp;
        unordered_map<char, bool> used;

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];
            
            if (mp.find(a) != mp.end()) {
                if (mp[a] != b) return false;
            }
            else if (used[b]) {
                return false;
            } else {
                mp[a] = b;
                used[b] = true;
            }
        }
        return true;
    }
};
