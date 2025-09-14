class Solution {
public:
    bool isValid(const vector<int>& piles, int mid, int h) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + mid - 1) / mid; // ceil(pile / mid)
            if (hours > h) return false;    // prune early
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(piles, mid, h)) {
                ans = mid;        // candidate answer
                high = mid - 1;   // try smaller speed
            } else {
                low = mid + 1;    // need more speed
            }
        }
        return ans;
    }
};
