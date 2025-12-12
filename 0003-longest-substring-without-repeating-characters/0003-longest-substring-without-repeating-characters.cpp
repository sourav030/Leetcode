class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int start = 0, end = 0;
        int ans = 0;

        while (end < s.length()) {
            mp[s[end]]++;

            while (mp[s[end]] > 1) {
                mp[s[start]]--;
                start++;
            }

            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};
