class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int>mp;
        for(auto ele:s){
            mp[ele]++;
        }
        for(auto ele:t){
            if(mp.find(ele)!=mp.end()){
                mp[ele]--;
                if(mp[ele]==0){
                    mp.erase(ele);
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};