class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0;
        int end=0;
        int ans=INT_MAX;
        int sum=0;
        while(end<nums.size()){
            sum+=nums[end];
            while(sum>=target and start<=end){
                ans=min(ans,end-start+1);
                sum-=nums[start];
                start++;
            }
            end++;
        }
        return ans==INT_MAX?0:ans;
    }
};