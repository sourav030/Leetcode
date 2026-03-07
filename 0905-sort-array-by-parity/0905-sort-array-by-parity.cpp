class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int start=0;
        int end=n-1;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                ans[start]=nums[i];
                start++;
            }
            else{
                ans[end]=nums[i];
                end--;
            }
        }
        return ans;
    }
};