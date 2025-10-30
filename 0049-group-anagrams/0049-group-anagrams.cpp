class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n=strs.size();
        map<string,vector<string>>mp;

        for(int i=0; i<n; i++){
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