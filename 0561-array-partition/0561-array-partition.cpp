class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int end=nums.size()-1;
        int sum=0;
        while(end>0){
            sum+=min(nums[end],nums[end-1]);
            end-=2;
        }
        return sum;
    }
};