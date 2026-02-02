class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=nums[idx]){
                idx=idx+1;
                nums[idx]=nums[i];
            }
        }
        return idx+1;
    }
};