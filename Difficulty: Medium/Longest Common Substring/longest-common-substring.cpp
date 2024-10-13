//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int find(int n, int m, string &s1,string &s2,int &ans,vector<vector<int>> &dp){
        if(n<=0 or m<=0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int len=0;
        if(s1[n-1]==s2[m-1]){
            len=1+find(n-1,m-1,s1,s2,ans,dp);
            ans=max(ans,len);
        }
        find(n-1,m,s1,s2,ans,dp);
        find(n,m-1,s1,s2,ans,dp);
        return dp[n][m]=len;
    }
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,-1));
        int ans=0;
        find(str1.size(),str2.size(),str1,str2,ans,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends