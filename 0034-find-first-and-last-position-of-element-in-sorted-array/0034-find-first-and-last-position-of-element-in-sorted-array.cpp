class Solution {
public:
    int solvefirst(vector<int>&nums, int target){
        int start=0;
        int end=nums.size()-1;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                ans=mid;
                end=mid-1;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
    int solveSecond(vector<int>&nums, int target){
        int start=0;
        int end=nums.size()-1;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                ans=mid;
                start=mid+1;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int a1=solvefirst(nums,target);
        int a2=solveSecond(nums, target);
        return {a1,a2};
    }
};