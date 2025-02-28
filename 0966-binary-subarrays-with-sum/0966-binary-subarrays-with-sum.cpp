class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumFreq;
        int sum = 0, count = 0;
        
        // Initialize prefix sum zero
        prefixSumFreq[0] = 1;
        
        for (int num : nums) {
            sum += num;  // Current prefix sum
            
            // Find subarrays with sum exactly equal to goal
            if (prefixSumFreq.find(sum - goal) != prefixSumFreq.end()) {
                count += prefixSumFreq[sum - goal];
            }
            
            // Store current prefix sum count
            prefixSumFreq[sum]++;
        }
        
        return count;
    }
};