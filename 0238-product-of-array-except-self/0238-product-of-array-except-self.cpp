class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);
        int prefix=nums[0];
        int suffix=nums[n-1];
        for(int i=1; i<nums.size(); i++){
            ans[i]=ans[i]*prefix;
            prefix=prefix*nums[i];
            cout<<ans[i]<<" ";
        }
        for(int i=nums.size()-2; i>=0; i--){
            ans[i]=ans[i]*suffix;
            suffix=suffix*nums[i];
        }
        return ans;
    }
};