//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int isValid(string& s) {
        int i = 0;
        int n = s.length();
        string value = "";
        int dotCount = 0;

        while (i < n) {
            if (!isdigit(s[i]) && s[i] != '.') {
                return false;
            }
            if (s[i] == '.') {
                if (value.length() == 0) return false; // empty block
                if (value.length() > 1 && value[0] == '0') return false; // leading zero
                int x = stoi(value);
                if (x > 255) return false;
                value = "";
                dotCount++;
            }
            else {
                value += s[i];
            }
            i++;
        }

        // After loop, check last block
        if (value.length() == 0) return false;
        if (value.length() > 1 && value[0] == '0') return false;
        int x = stoi(value);
        if (x > 255) return false;

        if (dotCount != 3) return false;

        return true;
    }
};



//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends