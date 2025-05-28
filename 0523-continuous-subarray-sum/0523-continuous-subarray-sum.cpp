class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modMap; // map from mod value to earliest index
        modMap[0] = -1; // to handle sum from beginning
        int runningSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            if (k != 0) runningSum %= k;
            
            if (modMap.find(runningSum) != modMap.end()) {
                if (i - modMap[runningSum] > 1) return true;
            } else {
                modMap[runningSum] = i;
            }
        }
        return false;
    }
};
