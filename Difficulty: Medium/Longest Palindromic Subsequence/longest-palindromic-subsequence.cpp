//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int solve(string s1,string s2,int n1, int n2, vector<vector<int>>&dp){
        if(n1==0 or n2==0) return 0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        if(s1[n1-1]==s2[n2-1]){
          return dp[n1][n2]= 1+solve(s1,s2,n1-1,n2-1,dp);
        }
        return dp[n1][n2]= max(solve(s1,s2,n1-1,n2,dp),solve(s1,s2,n1,n2-1,dp));
    }
    int longestPalinSubseq(string &s) {
        // code here
        string s1=s;
        reverse(s1.begin() ,s1.end());
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1]==s[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        return solve(s1,s,n,n,dp);
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

// } Driver Code Ends