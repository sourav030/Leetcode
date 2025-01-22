class Solution {
public:

    void solve(vector<vector<int>>&ans,vector<int>vec, int index, int n, vector<int>&nums){
        if(index==n){
            ans.push_back(vec);
            return;
        }
        solve(ans,vec, index+1, n, nums);
        vec.push_back(nums[index]);
        solve(ans,vec,index+1,n,nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>vec;
        vector<vector<int>> ans;
        int index=0;
        int n=nums.size();
        solve(ans,vec,index,n, nums);
        return ans;
    }
};