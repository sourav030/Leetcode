class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0;
        sort(nums.begin(), nums.end());
        for(int i=0; i< nums.size(); i++){
            if(x!=nums[i]){
                return x;
            }
            x++;
        }
        return x;
    }
};