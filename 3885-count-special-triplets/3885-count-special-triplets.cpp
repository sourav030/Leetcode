class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        map<int, vector<int>> mp;
        int n = nums.size();
        const int MOD = 1e9 + 7;

       
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int target = val * 2;

            if (mp.find(target) == mp.end()) continue;

            const vector<int>& indices = mp[target];

            
            long long count1 = lower_bound(indices.begin(), indices.end(), i) - indices.begin();

           
            long long count2 = indices.end() - upper_bound(indices.begin(), indices.end(), i);

            ans += (count1 * count2) % MOD;
            ans %= MOD;
        }

        return ans;
    }
};
