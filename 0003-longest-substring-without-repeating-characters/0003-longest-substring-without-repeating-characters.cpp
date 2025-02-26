class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st;
        int left=0;
        int right=0;
        int n=s.length();
        int maxLen=0;
        while(right<n){
            if(st.find(s[right])!=st.end()){
                while(left<right and st.find(s[right])!=st.end()){
                    st.erase(s[left]);
                    left++;
                }
            }
            st.insert(s[right]);
           int len=right-left+1;
            maxLen=max(len,maxLen);
            right++;
        }
        return maxLen;
       
    }
};