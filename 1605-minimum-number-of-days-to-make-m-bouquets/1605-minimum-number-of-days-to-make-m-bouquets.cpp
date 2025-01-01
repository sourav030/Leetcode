class Solution {
public:
    bool possible(vector<int>& arr, int day, int m, int k) {
        int count = 0;  // Consecutive flowers available
        int bouquet = 0;  // Total bouquets formed

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) {
                count++;
                if (count == k) {  // Form a bouquet
                    bouquet++;
                    count = 0;  // Reset count
                }
            } else {
                count = 0;  // Reset count as flowers are not blooming
            }
        }
        return bouquet >= m;  // Check if we can form at least m bouquets
    }

    int minDays(vector<int>& arr, int m, int k) {
        if(m>arr.size()){
            return -1;
        }
        if (m * k > arr.size()) {
            return -1;  // Not enough flowers to form m bouquets
        }

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(arr, mid, m, k)) {
                ans = mid;  // Update answer
                high = mid - 1;  // Look for smaller days
            } else {
                low = mid + 1;  // Look for larger days
            }
        }
        return ans;
    }
};
