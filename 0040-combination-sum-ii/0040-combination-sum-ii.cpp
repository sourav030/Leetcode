class Solution {
public:
    vector<vector<int>>st;
    void solve(vector<int>&candidates,vector<int>&arr, int idx, int target){
        if(target==0){
            st.push_back(arr);
            return;
        }
        if(idx>=candidates.size() or target<0){
            return;
        }
        arr.push_back(candidates[idx]);
        solve(candidates,arr,idx+1,target-candidates[idx]);
        arr.pop_back();
        while(idx+1<candidates.size() and candidates[idx]==candidates[idx+1]){
            idx++;
        }
        solve(candidates,arr,idx+1, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int idx=0;
        vector<int>nums;
        sort(candidates.begin(),candidates.end());
        solve(candidates,nums,idx, target);
        return st;
    }
};