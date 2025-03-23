//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string &digits) {
        // Code here
        int n = digits.size();
    if (n == 0 || digits[0] == '0') return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // Empty string has 1 way
    dp[1] = 1; // First character can be decoded only in one way

    for (int i = 2; i <= n; i++) {
        int oneDigit = digits[i - 1] - '0';   // Single digit
        int twoDigit = stoi(digits.substr(i - 2, 2)); // Two-digit number

        if (oneDigit >= 1) {
            dp[i] += dp[i - 1];
        }
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends