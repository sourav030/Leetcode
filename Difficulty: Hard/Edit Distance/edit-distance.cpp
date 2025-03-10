//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int solve(string& s1,string& s2, int n, int m, vector<vector<int>>&dp){
        if(n==0)
        {
            return m;
        }
        if(m==0){
            return n;
        }
        
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        
        if(s1[n-1]==s2[m-1]){
            return dp[n][m]= 0+ solve(s1,s2,n-1,m-1,dp);
        }
        else{
            return dp[n][m]=1+min({solve(s1, s2, n, m - 1, dp), // Insert
                                       solve(s1, s2, n - 1, m, dp), // Delete
                                       solve(s1, s2, n - 1, m - 1, dp)});
            
        }
        
        
    }
    int editDistance(string& s1, string& s2) {
        // code here
          int n=s1.size();
        
        int m=s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
      return  solve(s1,s2,n,m,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends