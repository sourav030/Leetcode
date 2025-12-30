class Solution {
public:
    int ans=0;
    void solve(vector<int>&nums, int idx, int sum, int target){
        if(idx==nums.size()){
            if(sum==target){
                ans++;
            }
            return;
        }
        solve(nums, idx+1,sum+nums[idx], target);
        solve(nums,idx+1,sum-nums[idx],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        solve(nums, 0, sum, target);
        return ans;
    }
};