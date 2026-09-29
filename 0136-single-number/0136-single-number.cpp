class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum=0;
        for(auto ele:nums){
            sum^=ele;
        }
        return sum;
    }
};