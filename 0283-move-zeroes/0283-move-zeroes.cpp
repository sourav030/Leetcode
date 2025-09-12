class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                nums[idx]=nums[i];
                idx++;
            }
        }
        while(idx<n){
            nums[idx]=0;
            idx++;
        }
    }
};