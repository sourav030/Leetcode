class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;

        int right=nums.size()-1;
        int left=0;
        if(nums[left]>nums[left+1] ) return left;
        if(nums[right]>nums[right-1]) return right;
        left=1;
        right=right-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1]){
                return mid;
            }
            if(nums[mid]>nums[mid-1]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return -1;
    }
};