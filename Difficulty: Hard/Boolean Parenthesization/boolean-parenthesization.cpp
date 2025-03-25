//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    unordered_map<string, int> dp;

int countWaysUtil(string &s, int i, int j, bool isTrue) {
    if (i > j) return 0; // Invalid case
    if (i == j) { // Base case: single character
        if (isTrue) return s[i] == 'T';
        else return s[i] == 'F';
    }

    // Creating a unique key for memoization
    string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
    if (dp.find(key) != dp.end()) return dp[key];

    int ways = 0;
    for (int k = i + 1; k < j; k += 2) { // k points to an operator
        int leftT = countWaysUtil(s, i, k - 1, true);
        int leftF = countWaysUtil(s, i, k - 1, false);
        int rightT = countWaysUtil(s, k + 1, j, true);
        int rightF = countWaysUtil(s, k + 1, j, false);

        if (s[k] == '&') {
            if (isTrue) ways += leftT * rightT;
            else ways += leftF * rightT + leftT * rightF + leftF * rightF;
        } 
        else if (s[k] == '|') {
            if (isTrue) ways += leftT * rightT + leftF * rightT + leftT * rightF;
            else ways += leftF * rightF;
        } 
        else if (s[k] == '^') {
            if (isTrue) ways += leftT * rightF + leftF * rightT;
            else ways += leftT * rightT + leftF * rightF;
        }
    }

    return dp[key] = ways;
}

int countWays(string &s) {
    dp.clear(); // Clear memoization for new input
    return countWaysUtil(s, 0, s.size() - 1, true);
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends