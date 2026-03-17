class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        int n=nums.size()-1;
        if(nums[n]>nums[n-1]){
            return n;
        }
        int start=1;
        int end=nums.size()-2;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1]){
                return mid;
            }
            else if(nums[mid]<nums[mid+1]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
};