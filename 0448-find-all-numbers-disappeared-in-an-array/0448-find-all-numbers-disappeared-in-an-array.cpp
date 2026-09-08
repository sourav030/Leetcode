class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int i=1;
        vector<int>ans;
        while(i<=n){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
            i++;
        }
        return ans;
    }
};