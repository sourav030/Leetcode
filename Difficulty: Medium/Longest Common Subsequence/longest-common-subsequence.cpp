//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
    // Function to find the length of longest common subsequence in two strings.
    int find(int n,int m,string &str1, string &str2,vector<vector<int>> &dp){
        if(n==0 or m==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(str1[n-1]==str2[m-1]){
            return dp[n][m]= 1+find(n-1,m-1, str1,str2,dp);
        }
        else{
            return dp[n][m]=max(find(n-1,m,str1,str2,dp),find(n,m-1,str1,str2,dp));
        }
    }
    int lcs(int n, int m, string str1, string str2) {
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return find(n,m ,str1,str2,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    }
    return 0;
}

// } Driver Code Ends