class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(int i=0; i<strs.size(); i++){
            string a=strs[i];
            sort(a.begin(),a.end());
            mp[a].push_back(strs[i]);
        }
        
        for(auto ele:mp){
            ans.push_back(ele.second);
        }
        return ans;
    }
};