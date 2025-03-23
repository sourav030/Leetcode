//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return the total number of possible unique BST.
  int solve(int n, vector<int>& dp) {
    if (n == 0 || n == 1) return 1;  // Base cases
    
    if (dp[n] != -1) return dp[n];  // Return precomputed result

    int result = 0;
    for (int i = 0; i < n; i++) {
        result += solve(i, dp) * solve(n - i - 1, dp);  // Recursive relation
    }
    
    return dp[n] = result;  // Store result in dp array
}
    int numTrees(int n) {
        // Your code here
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};


//{ Driver Code Starts.
#define mod (int)(1e9 + 7)

int main() {

    // taking total testcases
    int t;
    cin >> t;
    while (t--) {

        // taking total number of elements
        int n;
        cin >> n;
        Solution ob;
        // calling function numTrees()
        cout << ob.numTrees(n) << "\n";

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends