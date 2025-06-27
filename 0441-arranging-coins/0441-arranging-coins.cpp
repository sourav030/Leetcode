class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 0, high = n;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long coinsUsed = mid * (mid + 1) / 2;
            
            if (coinsUsed == n) {
                return mid;
            }
            else if (coinsUsed < n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};
