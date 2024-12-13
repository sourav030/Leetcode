//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(vector<int> &price, int n, int rod, vector<vector<int>> &dp){
        if(rod==0){
            return 0;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][rod]!=-1){
            return dp[n][rod];
        }
        if(n>rod){
            return dp[n][rod]=solve(price,n-1,rod,dp);
        }
        else{
            return dp[n][rod]= max(price[n-1]+solve(price,n,rod-n,dp), solve(price,n-1,rod,dp));
        }
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        int rod_length=n;
        vector<vector<int>> dp(n+1,vector<int>(rod_length+1,-1));
        return solve(price,n,rod_length,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends