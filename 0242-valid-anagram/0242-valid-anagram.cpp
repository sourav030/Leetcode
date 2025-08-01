class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(auto ele:s){
            mp[ele]++;
        }
        for(auto ele:t){
            mp[ele]--;
        }
        for(auto ele:mp){
            if(ele.second!=0){
                return false;
            }
        }
        return 1;
    }
};