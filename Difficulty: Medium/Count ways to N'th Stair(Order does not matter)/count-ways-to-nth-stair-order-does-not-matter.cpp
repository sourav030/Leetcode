//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int find(int index,int n,vector<int> &step,vector<vector<int>> &dp){
        if(n==0){
            return 1;
        }
        if(index==0){
            return 0;
        }
        if(dp[index][n]!=-1){
            return dp[index][n];
        }
        if(step[index-1]>n){
           return  dp[index][n]=find(index-1,n,step,dp);
        }
       return dp[index][n]=find(index,n-step[index-1],step,dp)+find(index-1,n,step,dp);
        
    }
  public:
    int nthStair(int n) {
        //  Code here
        vector<int>step(2);
        step[0]=1;
        step[1]=2;
        vector<vector<int>>dp(3,vector<int>(n+1,-1));
        return find(2,n,step,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.nthStair(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends