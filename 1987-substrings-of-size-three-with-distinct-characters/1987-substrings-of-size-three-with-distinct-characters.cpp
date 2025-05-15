class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.length()<3) return 0;
        int count = 0;
        for (int i = 0; i < s.length() - 2; i++) {
            unordered_set<char> st;
            st.insert(s[i]);
            st.insert(s[i + 1]);
            st.insert(s[i + 2]);
            if (st.size() == 3) {
                count++;
            }
        }
        return count;
    }
};
