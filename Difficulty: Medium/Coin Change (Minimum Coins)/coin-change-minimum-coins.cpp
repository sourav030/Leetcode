//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int> &coins, int sum, int i, vector<vector<int>> &dp) {
    if (sum == 0) return 0;   // Base Case: If sum is 0, no coins are needed.
    if (i >= coins.size() || sum < 0) return INT_MAX;  // Invalid case.

    if (dp[i][sum] != -1) return dp[i][sum];  // Memoization check.

    // Exclude the current coin
    int exclude = solve(coins, sum, i + 1, dp);
    
    // Include the current coin
    int include = INT_MAX;
    if (coins[i] <= sum) {
        int res = solve(coins, sum - coins[i], i, dp);
        if (res != INT_MAX) include = 1 + res;  // Avoid overflow
    }

    return dp[i][sum] = min(include, exclude);
}

int minCoins(vector<int> &coins, int sum) {
    vector<vector<int>> dp(coins.size(), vector<int>(sum + 1, -1));
    int ans = solve(coins, sum, 0, dp);
    return ans == INT_MAX ? -1 : ans;  // If no solution, return -1.
}
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends