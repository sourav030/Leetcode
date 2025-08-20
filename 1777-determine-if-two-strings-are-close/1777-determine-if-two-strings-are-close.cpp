class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if (n != m) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        for (int i = 0; i < n; i++) {
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }

        // Check if both words have the same set of characters
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        // Compare sorted frequency distributions
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};
