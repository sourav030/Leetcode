//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
int fun(vector<int> &val, vector<int> &wt, int w, int n, vector<vector<int>> &dp) {
    if (n == 0 || w == 0) {
        return 0; // Base case: no items or weight capacity
    }
    
    int itemWt = wt[n - 1];
    int itemVal = val[n - 1];

    if (dp[n][w] != -1) {
        return dp[n][w]; // Return memoized result if available
    }

    if (itemWt <= w) {
        int ans1 = fun(val, wt, w - itemWt, n - 1, dp) + itemVal; // Include the item
        int ans2 = fun(val, wt, w, n - 1, dp); // Exclude the item
        dp[n][w] = max(ans1, ans2); // Store the maximum of including or excluding
    } else {
        dp[n][w] = fun(val, wt, w, n - 1, dp); // Cannot include item
    }

    return dp[n][w]; // Return the computed value
}
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n=wt.size();
        vector<vector<int>>dp(n+1, vector<int>(W+1,-1));
        return fun(val,wt,W,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends