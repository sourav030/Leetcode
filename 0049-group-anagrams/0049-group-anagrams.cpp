class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(int i=0; i<strs.size(); i++){
            string a=strs[i];
            sort(a.begin(),a.end());
            mp[a].push_back(strs[i]);
        }
        vector<vector<string>>arr;
        for(auto ele:mp){
            arr.push_back(ele.second);
        }
        return arr;
    }
};