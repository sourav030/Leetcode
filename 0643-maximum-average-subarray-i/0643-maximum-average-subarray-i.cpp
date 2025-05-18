class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        int sum = 0;
        int start = 0;
        
        for (int end = 0; end < nums.size(); ++end) {
            sum += nums[end];
            if(end-start+1>k){
                sum-=nums[start];
                start++;
            }
            if (end - start + 1 == k) {
                double val = (double)sum / k;
                if (val > ans) {
                    ans = val;
                }
               
            }
        }
        
        return ans;
    }
};
