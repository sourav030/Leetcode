class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums, int idx, vector<int>&arr){
        if(idx>=nums.size()){
            ans.push_back(arr);
            return;
        }
        // take
        arr.push_back(nums[idx]);
        solve(nums, idx+1, arr);
        // not take 
        arr.pop_back();
        while(idx+1<nums.size() and nums[idx]==nums[idx+1]){
            idx++;
        }
        solve(nums, idx+1,arr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>arr;
        sort(nums.begin(), nums.end());
        int idx=0;
        solve(nums, idx, arr);
        return ans;
    }
};