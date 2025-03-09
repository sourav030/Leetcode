class Solution {
public:
   int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    int result = 0;
    unordered_map<long, int> mp[n]; // Array of hashmaps to store difference counts

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            long diff = (long)nums[i] - (long)nums[j]; // Avoid integer overflow
            auto it = mp[j].find(diff);
            int count_j = (it == mp[j].end()) ? 0 : it->second;

            mp[i][diff] += count_j + 1; // Increment count for subsequences ending at i
            result += count_j; // Only count subsequences of length >= 3
        }
    }
    return result; // You missed returning the result
}

};