class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++; // fixed here
        }

        unordered_set<int> st; // store used frequencies
        int result = 0;

        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0 && st.find(freq[i]) != st.end()) {
                freq[i]--;  // reduce frequency until unique
                result++;   // count deletions
            }
            if (freq[i] != 0) {
                st.insert(freq[i]); // mark frequency as used
            }
        }

        return result;
    }
};
