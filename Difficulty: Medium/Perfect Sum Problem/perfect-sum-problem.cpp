//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;

    int solve(vector<int>& arr, int target, int index, int cursum) {
        // If we reach the last index, check if the sum is equal to target
        if (index == arr.size()) {
            return (cursum == target) ? 1 : 0;
        }

        // If the result is already computed, return it
        if (dp[index][cursum] != -1) {
            return dp[index][cursum];
        }

        // Include the current element
        int include = solve(arr, target, index + 1, cursum + arr[index]);

        // Exclude the current element
        int exclude = solve(arr, target, index + 1, cursum);

        // Store and return the result
        return dp[index][cursum] = include + exclude;
    }

    int perfectSum(vector<int>& arr, int target) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        dp.assign(arr.size(), vector<int>(target + sum + 1, -1)); // Handle negative sums

        return solve(arr, target, 0, 0);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends