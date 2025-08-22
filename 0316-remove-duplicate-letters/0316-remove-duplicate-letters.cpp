class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result = "";
        vector<int> visited(26, 0);
        vector<int> lastIndex(26, 0);

        // Store last occurrence of each character
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            if (visited[idx]) continue;

            // Maintain lexicographical order with monotonic stack idea
            while (!result.empty() && result.back() > s[i] && lastIndex[result.back() - 'a'] > i) {
                visited[result.back() - 'a'] = 0;
                result.pop_back();
            }

            result.push_back(s[i]);
            visited[idx] = 1;
        }

        return result;
    }
};
