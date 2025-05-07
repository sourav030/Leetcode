class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        while (i < str1.size() && j < str2.size()) {
            char c = str1[i];
            char nextC = (c == 'z') ? 'a' : c + 1;
            if (str2[j] == c || str2[j] == nextC) {
                j++;
            }
            i++;
        }
        return j == str2.size();
    }
};
