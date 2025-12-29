class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int start=0;
        int end=0;
        int count=0;
        while(end<nums.size()){
            if(nums[end]==0){
                count++;
            }
            if(count>1){
                while(count>1){
                    if(nums[start]==0){
                        count--;
                    }
                    start++;
                }
            }
            ans=max(ans,end-start);
            end++;
        }
        return ans;
    }
};