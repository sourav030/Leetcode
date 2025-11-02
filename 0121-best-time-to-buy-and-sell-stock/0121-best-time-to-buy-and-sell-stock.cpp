class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans=-1;
        int minPrice=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            minPrice=min(minPrice,nums[i]);
            ans=max(ans,nums[i]-minPrice);
        }
        return ans;
    }
};