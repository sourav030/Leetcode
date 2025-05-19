class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        set<int>ans;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]]>1){
                ans.insert(nums[i]);
            }
        }
        vector<int>result(ans.begin(),ans.end());
        return result;
    }
};