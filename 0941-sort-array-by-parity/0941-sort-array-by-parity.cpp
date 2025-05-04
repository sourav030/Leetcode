class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int i=0;
        int j=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]%2==0){
                swap(nums[j],nums[i]);
                i++;
            }
            j++;
        }
        return nums;
    }
};