class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[start]<=nums[mid]){
                // Then Two case if formed

                //1 answer exist our not
                if(nums[start]<=target and target<nums[mid]){
                    end=mid-1;
                }
                // answer not exist in this part
                else{
                    start=mid+1;
                }
            }
            else{
                // two case answer exist our not
                if(nums[mid]<target and target<=nums[end]){
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