class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int target = totalSum % p;
        if (target == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        int curr = 0, res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            curr = (curr + nums[i]) % p;
            int finds = (curr - target + p) % p;

            if (mp.find(finds) != mp.end()) {
                res = min(res, i - mp[finds]);
            }

            mp[curr] = i;
        }

        return res == nums.size() ? -1 : res;
    }
};
