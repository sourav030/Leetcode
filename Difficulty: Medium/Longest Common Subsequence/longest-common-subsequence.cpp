//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
    int solve(string& s1, string& s2,int n,int m,vector<vector<int>> &dp){
        if(n<=0 or m<=0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        
        if(s1[n-1]==s2[m-1]){
            return  1+solve(s1,s2,n-1,m-1,dp);
        }
        else{
            return dp[n][m]= max(solve(s1,s2,n,m-1,dp),solve(s1,s2,n-1,m,dp));
        }
    }
  public:
    // Function to find the length of the longest common subsequence in two strings.
    int getLCSLength(string& s1, string& s2) {
        // your code here
        
        int n=s1.size();
        int m=s2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solve(s1,s2,n,m,dp);
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
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
        cout << ob.getLCSLength(s1, s2) << endl; // Call the getLCSLength function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends