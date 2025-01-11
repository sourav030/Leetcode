//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int longestUniqueSubstr(string &s) {
    unordered_map<char, int> mp;
    int start = 0;
    int maxSize = 0;

    for (int end = 0; end < s.length(); end++) {
        char a = s[end];

        if (mp.find(a) != mp.end() && mp[a] >= start) {
            start = mp[a] + 1;
        }

        mp[a] = end;
        maxSize = max(maxSize, end - start + 1);
    }

    return maxSize;
}

};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends