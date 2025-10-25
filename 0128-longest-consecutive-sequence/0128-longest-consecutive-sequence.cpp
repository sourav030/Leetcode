class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0; 

        sort(nums.begin(), nums.end());
        int count = 1;
        int ans = 1;                 
        int ele = nums[0];

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == ele) {
                continue;  
            } 
            else if(nums[i] == ele+1) {
                count++;
            } 
            else {
                count = 1;
            }
            ele = nums[i];   
            ans = max(ans, count);
        }
        return ans;
    }
};