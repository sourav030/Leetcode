class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        int missing=(n*(n+1)/2)-sum;
        return missing;
    }
};