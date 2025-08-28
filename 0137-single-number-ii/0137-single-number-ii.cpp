class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int ans=-1;
        for(auto ele:mp){
            if(ele.second==1){
                ans=ele.first;
                break;
            }
        }
        return ans;
    }
};