class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int zeroCount=0;
        int maxLen=0;

        while(right<nums.size()){
            if(nums[right]==0) zeroCount++;
            if(zeroCount>k){
                if(nums[left]==0) zeroCount--;
                left++;
            }
            if(zeroCount<=k){
                maxLen=max(maxLen,right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};