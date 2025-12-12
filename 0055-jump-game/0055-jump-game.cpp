class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(i>ans){
                return 0;
            }
            ans=max(ans, i+nums[i]);
        }
        return 1;
    }
};