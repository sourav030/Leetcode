//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int minChar(string& s) {
    string rev = s;
    reverse(rev.begin(), rev.end()); // Reverse the string
    string temp = s + '#' + rev;     // Concatenate with a delimiter

    int n = temp.length();
    vector<int> lps(n, 0);

    // Compute LPS array
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];

        while (j > 0 && temp[i] != temp[j]) {
            j = lps[j - 1];
        }

        if (temp[i] == temp[j]) {
            j++;
        }

        lps[i] = j;
    }

    // Minimum characters to add at the front
    return s.length() - lps[n - 1];
}
        // Write your code here
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends