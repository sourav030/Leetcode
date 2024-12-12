//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
  int solve(vector<int>& arr,int total_sum,int n,int sum ,vector<vector<int>> &dp){
      if(n==0){
          return abs((total_sum - sum) - sum);

      }
      if(dp[n][sum]!=-1){
          return dp[n][sum];
      }
      int include=INT_MAX;
      if(sum>=arr[n-1])
         include=solve(arr,total_sum,n-1,sum-arr[n-1],dp);
      
      int exclude=solve(arr,total_sum,n-1,sum,dp);
      return dp[n][sum]= min (include,exclude);
  }
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        int total_sum=0;
        for(int i=0; i< n; i++){
            total_sum+=arr[i];
        }
        vector<vector<int>> dp(n+1,vector<int>(total_sum+1,-1));
        return solve(arr,total_sum,n,total_sum,dp);
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends