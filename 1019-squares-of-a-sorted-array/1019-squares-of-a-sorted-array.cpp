class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            int val=pow(nums[i],2);
            ans.push_back(val);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};