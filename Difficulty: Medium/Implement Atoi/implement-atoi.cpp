//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
int myAtoi(char *s) {
    int i = 0; // Pointer to traverse the string
    int sign = 1; // Default sign is positive
    long result = 0; // Store the result as long to handle overflow during conversion

    // Step 1: Skip leading whitespaces
    while (s[i] == ' ') {
        i++;
    }

    // Step 2: Handle the optional sign
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // Step 3: Convert digits to integer
    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');

        // Step 4: Check for overflow
        if (result * sign > INT_MAX) {
            return INT_MAX;
        } else if (result * sign < INT_MIN) {
            return INT_MIN;
        }
        i++;
    }

    // Step 5: Return the final result with the sign
    return (int)(result * sign);
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends