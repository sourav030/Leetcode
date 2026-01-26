class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";

        for (int i = s.length() - 1; i >= 0; i--) {

            if (s[i] != ' ') {
                word = s[i] + word;
            } 
            else {
                if (!word.empty()) {
                    if (!ans.empty()) ans += " ";
                    ans += word;
                    word = "";
                }
            }
        }

        if (!word.empty()) {
            if (!ans.empty()) ans += " ";
            ans += word;
        }

        return ans;
    }
};
