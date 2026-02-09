class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums, int idx, int target, vector<int>arr){
        if(target==0){
            ans.push_back(arr);
            return ;
        }
        if(target<0 or idx>=nums.size()){
            return;
        }
        arr.push_back(nums[idx]);
        solve(nums,idx+1,target-nums[idx], arr);
        arr.pop_back();
        while(idx+1<nums.size() and nums[idx]==nums[idx+1]){
            idx++;
        }
        solve(nums,idx+1,target,arr);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int idx=0;
        vector<int>ar;
        solve(candidates, idx,target,ar);
        return ans;

    }
};