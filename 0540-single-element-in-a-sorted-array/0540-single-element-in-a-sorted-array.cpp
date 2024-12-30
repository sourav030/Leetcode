class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        if(nums.size()==1) return nums[0];
        if(nums[start]!=nums[start+1]) return nums[start];
        if(nums[end]!=nums[end-1]) return nums[end];
        
        while(start<=end){
            int mid=start+(end-start)/2;

            if(nums[mid]!=nums[mid+1] and nums[mid]!=nums[mid-1]){
                return nums[mid];
            }

           if((mid%2==1 and nums[mid]==nums[mid-1]) or (mid%2==0 and nums[mid]==nums[mid+1])){
             start = mid + 1;
            }
        else{
             end = mid - 1;
        }
        }
        return -1;
    }
};