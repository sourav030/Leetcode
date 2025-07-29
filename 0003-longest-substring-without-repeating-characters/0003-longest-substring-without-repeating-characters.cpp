class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int end=0;
        unordered_set<char>st;
        int size=0;
        while(end<s.length()){
            if(st.find(s[end])==st.end()){
                st.insert(s[end]);
            }
            else{
                while( !st.empty() and st.find(s[end])!=st.end()){
                    st.erase(s[start]);
                    start++;
                }
                st.insert(s[end]);
            }
            size=max(size,(end-start+1));
            end++;
        }
        return size;
    }
};