//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    int carry = 0;
    std::string result = "";

    // Start from the end of both strings and add bit by bit
    int i = n1 - 1, j = n2 - 1;
    while (i >= 0 || j >= 0 || carry) {
        int bit1 = (i >= 0) ? s1[i] - '0' : 0;
        int bit2 = (j >= 0) ? s2[j] - '0' : 0;

        int sum = bit1 + bit2 + carry;
        result += (sum % 2) + '0';  // Append the current bit to the result
        carry = sum / 2;            // Calculate the new carry

        i--;
        j--;
    }

    // Reverse the result string to get the final binary string
    std::reverse(result.begin(), result.end());

    // Remove leading zeros, if any
    auto nonZeroPos = result.find_first_not_of('0');
    if (nonZeroPos != std::string::npos) {
        return result.substr(nonZeroPos);
    }

    return "0"; // If the result is all zeros
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends