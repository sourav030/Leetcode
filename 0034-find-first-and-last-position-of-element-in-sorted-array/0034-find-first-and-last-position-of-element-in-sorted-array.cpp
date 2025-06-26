class Solution {
public:
    int findFirst(vector<int>&nums, int target){
        int ans=-1;
        int low=0;
        int end=nums.size()-1;
        while(low<=end){
            int mid=low+(end-low)/2;
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
    int findLast(vector<int>&nums, int target){
        int ans=-1;
        int low=0;
        int end=nums.size()-1;
        while(low<=end){
            int mid=low+(end-low)/2;
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
         int a=findFirst(nums,target);
         int b = findLast(nums, target);
         return {a,b};
    }
};