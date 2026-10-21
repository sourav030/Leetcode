class Solution {
public:
    vector<vector<int>>arr;
    void solve(vector<int>&nums, int idx){
        if(idx>=nums.size()){
            arr.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx],nums[i]);
            solve(nums,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int idx=0;
        solve(nums,idx);
        return arr;
    }
};