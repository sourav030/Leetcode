class Solution {
public:

    vector<vector<int>>ans;
    void solve(vector<int>&nums, vector<int>arr, int idx, int target){
        if(target==0){
            ans.push_back(arr);
            return;
        }
        if(idx>=nums.size() or target<0){
            return;
        }
        // first we take the element
        arr.push_back(nums[idx]);
        solve(nums,arr,idx, target-nums[idx]);
        arr.pop_back();
        solve(nums,arr,idx+1,target); // exclude
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>a;
        int idx=0;
        solve(candidates,a,idx,target);
        return ans;
    }
};