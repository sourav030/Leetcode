class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        int start=0;
        int end=0;
        unordered_map<int,int>mp;
        long long sum=0;
        while(end<nums.size()){

            while(mp.find(nums[end])!=mp.end() and start<=end){
                sum-=nums[start];
                mp[nums[start]]--;
                if(mp[nums[start]]==0){
                    mp.erase(nums[start]);
                }
                start++;
            }

            mp[nums[end]]++;
            sum+=nums[end];
            if(end-start+1==k){
                ans=max(ans,sum);
                sum-=nums[start];
                mp[nums[start]]--;
                if(mp[nums[start]]==0){
                    mp.erase(nums[start]);
                }
                start++;
            }
            end++;
        }
        return ans==INT_MIN? 0:ans;
    }
};