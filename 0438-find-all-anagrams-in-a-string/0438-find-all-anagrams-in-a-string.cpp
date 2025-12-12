class Solution {
public:
    bool check(unordered_map<char,int>mp, string str){
        for(auto ele:str){
            if(mp[ele]!=0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int start=0;
        int end=0;
        vector<int>ans;
        unordered_map<char,int>mp;
        for(auto ele:p){
            mp[ele]++;
        }
        while(end<s.length()){
            if(mp.find(s[end])!=mp.end()){
                mp[s[end]]--;
            }
            if(end-start+1==p.length()){
                if(check(mp,p)){
                    ans.push_back(start);
                }
                if(mp.find(s[start])!=mp.end()){
                    mp[s[start]]++;
                }
                start++;
            }
            end++;
        }
        return ans;
    }
};