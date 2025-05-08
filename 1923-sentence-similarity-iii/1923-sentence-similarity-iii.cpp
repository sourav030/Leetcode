class Solution {
public:
    vector<string> split(string s) {
        vector<string> res;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            res.push_back(word);
        }
        return res;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1 = split(sentence1);
        vector<string> s2 = split(sentence2);

        // Make sure s1 is the longer one
        if (s1.size() < s2.size()) swap(s1, s2);

        int n1 = s1.size(), n2 = s2.size();
        int left = 0;

        // Match from left
        while (left < n2 && s1[left] == s2[left]) left++;

        // Match from right
        int right = 0;
        while (right < n2 - left && s1[n1 - 1 - right] == s2[n2 - 1 - right]) right++;

        return left + right == n2;
    }
};
