//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int solve(string &s,string &s1,int n, int m ,  vector<vector<int>> &dp){
        if (n==0 || m==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s[n-1]==s1[m-1]){
            return dp[n][m]= 1+solve(s,s1,n-1,m-1,dp);
        }
        else{
            return dp[n][m]= max(solve(s,s1,n,m-1,dp),solve(s,s1,n-1,m,dp));
        }
    }
  public:
    int longestPalinSubseq(string &s) {
        // code here
        string s1=s;
        reverse(s1.begin(),s1.end());
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(s,s1,n,n,dp);
    }
};

//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends