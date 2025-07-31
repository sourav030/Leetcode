class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int idx=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=val){
                idx++;
                nums[idx]=nums[i];
            }
            else{
                count++;
            }
        }
        return idx+1;
    }
};