class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
        int idx=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=0){
                nums[idx]=nums[i];
                idx++;
            }
            i++;
        }
        while(idx<nums.size()){
            nums[idx]=0;
            idx++;
        }
        return nums;
    }
};