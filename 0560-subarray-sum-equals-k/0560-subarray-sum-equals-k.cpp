class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int sum=0;
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            }
            int val=sum-k;
            if(mp.find(val)!=mp.end()){
                count+=mp[val];
            }
            mp[sum]++;
        }
        return count;
    }
};