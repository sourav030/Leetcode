class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])!=mp.end()){
                mp[nums[i]]++;
            }
            else{
                mp[nums[i]]=1;
            }
        }

        for(auto it:mp){
            if(it.second>n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};