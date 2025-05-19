class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto ele:nums){
            if(mp.find(ele)!=mp.end()) return true;
            mp[ele]=1;
        }
        return false;
    }
};