class Solution {
public:
    bool isSubsequence(const string& word, const string& s) {
        int i = 0, j = 0;
        while (j < s.length() && i < word.length()) {
            if (word[i] == s[j]) i++;
            j++;
        }
        return i == word.length();
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int> freq;
        for (const auto& word : words) {
            freq[word]++;
        }

        int count = 0;
        for (const auto& [word, occ] : freq) {
            if (isSubsequence(word, s)) {
                count += occ;
            }
        }

        return count;
    }
};
