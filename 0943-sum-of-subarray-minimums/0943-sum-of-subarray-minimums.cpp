class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        // Vectors to store Previous Smaller Element (PSE) and Next Smaller Element (NSE)
        vector<int> prev_smaller(n, -1);
        vector<int> next_smaller(n, n);

        // Monotonic stack for PSE
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            prev_smaller[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear the stack for NSE
        while (!s.empty()) s.pop();

        // Monotonic stack for NSE
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            next_smaller[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Calculate the sum of minimums
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prev_smaller[i];   // Distance to PSE
            long long right = next_smaller[i] - i; // Distance to NSE
            result = (result + arr[i] * left * right) % MOD;
        }

        return result;
    }
};