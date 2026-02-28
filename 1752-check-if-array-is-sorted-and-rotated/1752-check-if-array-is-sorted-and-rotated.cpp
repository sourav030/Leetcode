class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<nums[i-1]){
                count++;
            }
        }
        int n=nums.size();
        if(nums[0]<nums[n-1]){
            count++;
        }
        return count<=1;
    }
};