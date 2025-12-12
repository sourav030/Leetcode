class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum==k){
                ans++;
            }
            int val=sum-k;
            if(mp.find(val)!=mp.end()){
                ans+=mp[val];
            }
            mp[sum]++;
        }
        return ans;
    }
};