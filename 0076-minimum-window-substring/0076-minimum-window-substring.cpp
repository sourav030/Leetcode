class Solution {
public:
    bool check(unordered_map<char, int> &mp) {
        for (auto ele : mp) {
            if (ele.second > 0) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (auto ele : t) {
            mp[ele]++;
        }

        int start = 0;
        int end = 0;
        int ans = INT_MAX;
        int st = -1;

        while (end < s.length()) {
            mp[s[end]]--;

            while (check(mp) && start <= end) {
                if (end - start + 1 < ans) {
                    ans = end - start + 1;
                    st = start;
                }

                mp[s[start]]++;
                start++;
            }

            end++;
        }

        if (st == -1) return "";
        return s.substr(st, ans);  
    }
};