class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivotIndex=-1;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                pivotIndex=i;
                break;
            }
        }
        if(pivotIndex==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1; i>pivotIndex; i--){
            if(nums[i]>nums[pivotIndex]){
                swap(nums[i],nums[pivotIndex]);
                break;
            }
        }

        reverse(nums.begin()+pivotIndex+1,nums.end());
        return;
    }
};