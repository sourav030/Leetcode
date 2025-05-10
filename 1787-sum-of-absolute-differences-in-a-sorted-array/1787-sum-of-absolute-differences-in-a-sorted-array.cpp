class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> result(n, 0);
        
      
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        
        
        for (int i = 0; i < n; i++) {
           
            int left = nums[i] * i - (i > 0 ? prefix[i - 1] : 0);
            
            
            int right = (prefix[n - 1] - prefix[i]) - nums[i] * (n - i - 1);
            
            result[i] = left + right;
        }
        
        return result;
    }
};
