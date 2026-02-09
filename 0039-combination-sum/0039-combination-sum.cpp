class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&arr, int idx, int target, vector<int>nums){
        if(target==0){
            ans.push_back(nums);
            return;
        }
        if(idx>=arr.size() or target<0){
            return;
        }
        nums.push_back(arr[idx]);
        solve(arr, idx, target-arr[idx], nums);
        nums.pop_back();
        solve(arr, idx+1, target, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int idx=0;
        vector<int>nums;
        solve(candidates,idx, target,nums);
        return ans;
    }
};