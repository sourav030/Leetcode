class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int x=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                nums[x]=nums[i];
                x++;
            }
        }
        for(int j=x; j<nums.size(); j++){
            nums[j]=0;
        }
    }
};