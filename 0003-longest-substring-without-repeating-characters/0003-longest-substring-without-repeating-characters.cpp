class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int start=0;
        int end=0;
        unordered_map<char,int>mp;

        while(end<s.length()){
            if(mp.find(s[end])==mp.end()){
                mp[s[end]]=1;
            }
            else{
                while(mp.find(s[end])!=mp.end() and start<end){
                    mp.erase(s[start]);
                    start++;
                }
                mp[s[end]]=1;
            }
            
            if(mp.size()>ans){
                ans=mp.size();
            }
            end++;
        }
        return ans;
    }
};