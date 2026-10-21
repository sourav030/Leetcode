class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&candidates, vector<int>&arr, int idx, int target){
        if(target==0){
            ans.push_back(arr);
            return;
        }
        if(target<0 or idx>=candidates.size()){
            return;
        }
        arr.push_back(candidates[idx]);
        solve(candidates,arr,idx,target-candidates[idx]);
        arr.pop_back();
        solve(candidates,arr,idx+1, target);
    

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>arr;
        int idx=0;
        solve(candidates,arr, idx, target);
        return ans;
    }
};