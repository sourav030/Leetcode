class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int end=nums.size()-1; 
        int ans=0;
        while(low<=end){
            int mid=low+(end-low)/2;
            if(nums[mid]<target){
                ans=mid+1;
                low=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};