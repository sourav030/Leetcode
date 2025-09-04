class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&arr, vector<int>&nums, int sum, int target, int index){
        if(sum==target){
            ans.push_back(nums);
            return;
        }
        if(index>=arr.size() or sum>target){
            return;
        }
        nums.push_back(arr[index]);
        solve(arr, nums, sum+arr[index], target, index);
        nums.pop_back();
        solve(arr, nums, sum, target, index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>nums; 
        solve(candidates, nums, 0,target,0);
        return ans;
    }
};