class Solution {
public:
    long long find(vector<int>& arr, int time) {
        long long total = 0;  // Use long long to handle large totals
        for (int i = 0; i < arr.size(); i++) {
            total += arr[i] / time;  // Add the number of full hours required for each pile
            if (arr[i] % time) {      // If there's a remainder, add an extra hour
                total++;
            }
        }
        return total;  // Return total hours needed at the given speed
    }

    int minEatingSpeed(vector<int>& arr, int h) {
        long long low = 1;  // Use long long to avoid overflow
        long long high = LLONG_MIN;  // Use LLONG_MIN for proper long long range
        for (int i = 0; i < arr.size(); i++) {
            high = max(high, (long long)arr[i]);  // Ensure high is a long long
        }
        
        int ans = high;  // Initialize the answer with the maximum eating speed
        while (low <= high) {
            long long mid = low + (high - low) / 2;  // Use long long for mid to prevent overflow
            long long totalHour = find(arr, mid);
            if (totalHour <= h) {
                ans = mid;  // Update answer with the current speed
                high = mid - 1;  // Try for a smaller speed
            } else {
                low = mid + 1;  // Try for a larger speed
            }
        }
        return ans;  // Return the minimum speed that allows finishing within 'h' hours
    }
};