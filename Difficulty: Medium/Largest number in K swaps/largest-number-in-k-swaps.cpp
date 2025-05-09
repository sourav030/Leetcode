//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    string maxStr;

    // Helper function for backtracking
    void findMaximum(string& s, int k, int index) {
        if (k == 0)
            return;

        char maxDigit = s[index];
        for (int i = index + 1; i < s.size(); i++) {
            if (s[i] > maxDigit)
                maxDigit = s[i];
        }

        // Only proceed if there's a better digit to swap
        if (maxDigit != s[index])
            k--;

        for (int i = s.size() - 1; i >= index; i--) {
            if (s[i] == maxDigit) {
                swap(s[index], s[i]);
                if (s > maxStr)
                    maxStr = s;

                findMaximum(s, k, index + 1);
                swap(s[index], s[i]);  // backtrack
            }
        }
    }

    string findMaximumNum(string& s, int k) {
        maxStr = s;
        findMaximum(s, k, 0);
        return maxStr;
    }
};



//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends