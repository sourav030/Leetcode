class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        unordered_set<int>st;
        int start=0;
        int end=0;
        long long ans=0;
        while(end<nums.size()){
            while(st.find(nums[end])!=st.end()){
                sum-=nums[start];
                st.erase(nums[start]);
                start++;
            }
            sum+=nums[end];
            st.insert(nums[end]);
            if(end-start+1>k){
                sum-=nums[start];
                st.erase(nums[start]);
                start++;
            }
            if(end-start+1==k)
            ans=max(sum,ans);
            end++;
        }
        return ans;
    }
};