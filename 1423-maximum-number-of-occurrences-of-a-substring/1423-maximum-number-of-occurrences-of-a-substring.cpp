class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int>mp;
        int len=0;
        for(int i=0; i<=s.length()-minSize; i++){
            string ans=s.substr(i,minSize);
            unordered_set<char>st(ans.begin(),ans.end());
            if(st.size()<=maxLetters){
                mp[ans]++;
                len=max(len,mp[ans]);
            }
        }
        return len;
    }
};