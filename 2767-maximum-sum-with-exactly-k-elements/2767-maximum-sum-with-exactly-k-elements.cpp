class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        int sum=0;
        while(k--){
            int a=nums[n];
            nums.pop_back();
            nums.push_back(a+1);
            sum+=a;
        }
        return sum;
    }
};