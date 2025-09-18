class Solution {
public:
    bool solve(vector<int>&nums, int sum, int k){
        int count=1;
        int currsum=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>sum){
                return false;
            }
            if(currsum+nums[i]>sum){
                currsum=nums[i];
                count++;
            }
            else{
                currsum+=nums[i];
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=0;
        int high=0;
        for(int i=0; i<nums.size(); i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(nums,mid, k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};