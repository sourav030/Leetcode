class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums, int index, int n){
        if(index>=n){
            ans.push_back(nums);
            return;
        }
        vector<bool>used(22,0);
        for(int i=index; i<nums.size(); i++){
            if(used[nums[i]+10]==0){
                used[nums[i]+10]=1;
                swap(nums[i],nums[index]);
                solve(nums, index+1,n);
                swap(nums[i],nums[index]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        solve(nums, 0,n);
        return ans;
    }
};