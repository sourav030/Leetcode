//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long int find(int n ,int sum,int coin[],vector<vector<long long int>> &dp){
      // agar sum zero hai to woh ban gya hai
      // to return kr denge 1
      if(sum==0){
          return 1;
      }
      if(n<=0 ){
          return 0;// iska matlab ab hamre pass coin nhi hai
      }
      
      if(dp[n][sum]!=-1){
          return dp[n][sum];
      }
      // hum coin ko tab lenge jab woh sum se chota ho nhi to skip kr denge
      if(coin[n-1]>sum){
          return dp[n][sum]=find(n-1,sum,coin,dp);
      }
      else{
          return dp[n][sum]= find(n,sum-coin[n-1],coin,dp) + find(n-1,sum,coin,dp);
      }
  }
    long long int count(int coins[], int N, int sum) {

        // code here.
        // for top down approch
        // vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,-1));
        // return find(N,sum,coins,dp);
        
        // for bottom up
        vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,-0));
        // fill the value 1 where coloum=0
        for(int i=0; i< N+1; i++){
            dp[i][0]=1;
        }
        
        for(int i=1; i<N+1; i++){
            for(int j=1; j<sum+1; j++){
                if(coins[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                }
            }
        }
        
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends