//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the nth catalan number.
    int solve(int n, vector<int>& dp){
         if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int res=0;
        for(int i=0; i<n; i++){
            res+=solve(i,dp)*solve(n-i-1,dp);
        }
        return dp[n]= res;
    }
    int findCatalan(int n) {
        // code here
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        Solution obj;
        cout << obj.findCatalan(n) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends