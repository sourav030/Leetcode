class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int start=0;
        int end=0;
        unordered_map<char,int>mp;
        while(end<s.length()){
            if(mp.find(s[end])==mp.end()){
                mp[s[end]]++;
            }
            else{
                while(start<end and mp.find(s[end])!=mp.end()){
                    mp.erase(s[start]);
                    start++;
                }
                mp[s[end]]++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};