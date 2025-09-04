class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums, int index, int n){
        if(index>=n){
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[i],nums[index]);
            solve(nums, index+1, n);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        solve(nums, 0, n);
        return ans;
    }
};