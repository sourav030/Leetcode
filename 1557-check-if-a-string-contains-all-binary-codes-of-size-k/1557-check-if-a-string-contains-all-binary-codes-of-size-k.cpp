class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k > s.length()) return false;
       unordered_set<string> st;
       for(int i = 0; i <= s.length() - k; i++) {
          st.insert(s.substr(i, k));
       }
       return st.size() == pow(2, k);
    }
};

