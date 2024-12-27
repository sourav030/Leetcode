class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> &vec, int index){
        if(index==nums.size()){
            ans.push_back(vec);
            return;
        }
        // include operation
        vec.push_back(nums[index]);
        solve(nums,ans,vec, index+1);
        // perform exclude operation after skip the duplicate element
        vec.pop_back();
        int idx=index+1;
        while(idx<nums.size() and nums[idx]==nums[idx-1]){
            idx++;
        }
        solve(nums,ans,vec, idx);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>vec;
        solve(nums,ans,vec,0);
        return ans;
    }
};