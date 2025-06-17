class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        long long minCoins = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            int minPile = arr[i];
            int maxAllowed = minPile + k;

            // Binary search for first element > maxAllowed
            auto it = upper_bound(arr.begin(), arr.end(), maxAllowed);
            int idx = it - arr.begin();

            // Coins to remove:
            // 1. Remove all coins from 0 to i-1
            long long coinsBefore = prefix[i];

            // 2. Remove excess coins from idx to end
            long long coinsAfter = prefix[n] - prefix[idx];
            long long countAfter = n - idx;
            long long excess = coinsAfter - (countAfter * 1LL * maxAllowed);

            long long total = coinsBefore + (excess > 0 ? excess : 0);
            minCoins = min(minCoins, total);
        }

        return (int)minCoins;
    }
};
