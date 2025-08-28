class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        int ans=0;
        int start=0;
        int end=start+1;
        sort(nums.begin(),nums.end());
        while(end<nums.size()){
            int sub=nums[end]-nums[start];
            ans=max(ans,sub);
            start++;
            end++;
        }
        return ans;
    }
};