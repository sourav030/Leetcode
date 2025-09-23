class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (!word.empty()) {
                    if (!ans.empty()) ans = " " + ans;
                    ans = word + ans;
                    word = "";
                }
            }
        }
        
        if (!word.empty()) {
            if (!ans.empty()) ans = " " + ans;
            ans = word + ans;
        }
        
        return ans;
    }
};
