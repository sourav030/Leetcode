class Solution {
        void Subset(vector<vector<int>>&ans,vector<int>nums,int index,int end, vector<int>arr)
        {
                if(index>end)
                {
                        ans.push_back(arr);
                        return;
                }
                Subset(ans,nums,index+1,end,arr);
                arr.push_back(nums[index]);
                Subset(ans,nums, index+1, end, arr);
        }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
            int index=0;
            int end=nums.size()-1;
            vector<int>arr;
            Subset(ans,nums,index,end,arr);
            return ans;
    }
};