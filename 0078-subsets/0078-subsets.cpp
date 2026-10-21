class Solution {
public:
    vector<vector<int>>Ans;
    void solve(vector<int>&nums, vector<int>&ans, int idx){
        if(idx>=nums.size()){
            Ans.push_back(ans);
            return;
        }
       
        solve(nums, ans, idx+1);
        ans.push_back(nums[idx]);
        solve(nums, ans, idx+1);
        ans.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        solve(nums, ans,0);
        return Ans;
    }
};