//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    int find(int n,int m, string &s, string &s1,vector<vector<int>> &dp){
        if(n<=0 or m<=0)
        return 0;
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s[n-1]==s1[m-1]){
            return dp[n][m]= 1+find(n-1,m-1,s,s1,dp);
        }
        else {
            return dp[n][m]= max(find(n-1,m,s,s1,dp),find(n,m-1,s,s1,dp));
        }
    }
  public:
    int countMin(string str){
    //complete the function here
    int n=str.size();
    string str1=str;
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    reverse(str1.begin(), str1.end() );
    int x =find(n,n,str,str1,dp);
    return n-x;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends