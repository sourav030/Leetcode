class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int ans=-1;

        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[start]<=nums[mid]){
                // this is sorted part
                if(nums[start]<=target and nums[mid]>=target){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
               
            }
            else{
                if(nums[mid]<=target and  nums[end]>=target){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};