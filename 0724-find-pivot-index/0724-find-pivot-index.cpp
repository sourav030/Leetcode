class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefixSum=0;
        for(int i=0; i<nums.size(); i++){
            prefixSum+=nums[i];
        }
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            int remainSum=prefixSum-sum;
            int prevSum=sum-nums[i];;
            if(prevSum==remainSum){
                return i;
            }
        }
        return -1;
    }
};