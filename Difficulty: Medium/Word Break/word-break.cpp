//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n+1, false);

        dp[0] = true;

        for(int i=1; i<=n; i++) {
            for (const string &w : wordDict) {
                int start = i - w.length();
                if(start >= 0 && dp[start] && s.substr(start, w.length()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];        
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends