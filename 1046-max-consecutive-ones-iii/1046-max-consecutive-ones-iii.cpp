class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int end=0;
        int start=0;
        int count=0;
        int ans=0;
        while(end<nums.size()){
            if(nums[end]==0){
                count++;
            }
            if(count>k){
                if(nums[start]==0){
                    count--;
                }
                start++;
            }
            
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};