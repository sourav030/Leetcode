
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            }
            else {
                if (word.length() > 0) {
                    if (ans.length() > 0)
                        ans = word + " " + ans;
                    else
                        ans = word;
                }

                word = "";
            }
        }

        if (word.length() > 0) {
            if (ans.length() > 0)
                ans = word + " " + ans;
            else
                ans = word;
        }

        return ans;
    }
};

