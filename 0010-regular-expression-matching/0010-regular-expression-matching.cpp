class Solution {
public:
    bool solve(int idx1, int idx2, string &s, string &p) {
        //  Pattern khatam ho gaya
        if (idx2 == p.length()) return idx1 == s.length();

        //  String khatam ho gayi, pattern abhi bacha hai
        if (idx1 == s.length()) {
            while (idx2 + 1 < p.length() && p[idx2 + 1] == '*') {
                idx2 += 2;
            }
            return idx2 == p.length();
        }

        bool match = (s[idx1] == p[idx2] || p[idx2] == '.');

        if (idx2 + 1 < p.length() && p[idx2 + 1] == '*') {
            return solve(idx1, idx2 + 2, s, p) || (match && solve(idx1 + 1, idx2, s, p));
        } else {
            return match && solve(idx1 + 1, idx2 + 1, s, p);
        }
    }

    bool isMatch(string s, string p) {
        return solve(0, 0, s, p);
    }
};
