//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  private:
    string s;
    vector<vector<int>> dp;

  public:
    bool isPalindrome(int i, int j) {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = (s[i] == s[j] && isPalindrome(i + 1, j - 1));
    }

    string longestPalindrome(string str) {
        s = str;
        int n = s.length();
        dp.assign(n, vector<int>(n, -1));

        int start = 0, maxLength = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j) && j - i + 1 > maxLength) {
                    start = i;
                    maxLength = j - i + 1;
                }
            }
        }
        return s.substr(start, maxLength);
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends