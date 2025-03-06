//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(string &s1,string &s2,int n1,int n2, vector<vector<int>>&dp){
        if(n1<=0 or n2<=0) return 0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        if(s1[n1-1]==s2[n2-1]){
            dp[n1][n2]= 1+solve(s1,s2,n1-1,n2-1,dp);
            return dp[n1][n2];
        }
        int x=solve(s1,s2,n1-1,n2,dp);
        int y=solve(s1,s2,n1,n2-1,dp);
        dp[n1][n2]= max(x,y);
        return dp[n1][n2];
    }
    int lcs(string &s1, string &s2) {
        // code here
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return solve(s1,s2,s1.size(),s2.size(),dp);
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends