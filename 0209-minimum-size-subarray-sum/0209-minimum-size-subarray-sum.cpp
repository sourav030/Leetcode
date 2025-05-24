class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int start=0;
        int end=0;
        long long sum=0;
        while(end<nums.size()){
            sum+=nums[end];
            while(sum>=target){
                ans=min(ans,end-start+1);
                sum=sum-nums[start];
                start++;
            }
            
            end++;
            
        }
        return ans==INT_MAX?0:ans;
    }
};