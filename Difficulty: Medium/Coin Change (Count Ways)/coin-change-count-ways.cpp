//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(vector<int>& coins, int sum,int n,vector<vector<int>>dp){
      if(sum==0){
          return 1;
      }
      if(n==0 ){
          return 0;
      }
      if(dp[n][sum]!=-1){
          return dp[n][sum];
      }
      if(coins[n-1] > sum){
          return dp[n][sum]= solve(coins,sum,n-1,dp);
      }
      else{
          dp[n][sum]= solve(coins,sum-coins[n-1],n,dp)+solve(coins,sum, n-1,dp);
      }
       return dp[n][sum];
  }
    int count(vector<int>& coins, int sum) {
        // code here.
    
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-0));
        for(int i=0; i<=n; i++){
            dp[i][0]=1;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(coins[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
        return solve(coins,sum,n,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends