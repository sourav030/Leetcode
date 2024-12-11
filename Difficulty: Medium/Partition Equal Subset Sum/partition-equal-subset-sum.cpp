//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool solve(vector<int>arr, int sum, int n,  vector<vector<int>> &dp){
      if(sum==0){
          return 1;
      }
      if(n<=0 or sum < 0){
          return 0;
      }
      
      if(dp[n][sum]!=-1){
          return dp[n][sum];
      }
      
      if(arr[n-1]>sum){
         dp[n][sum]=solve(arr,sum,n-1,dp);
          return dp[n][sum];
          
      }
      
      else{
          bool include=solve(arr,sum-arr[n-1],n-1,dp);
          bool exclude=solve(arr,sum,n-1,dp);
          return dp[n][sum]= include || exclude;
      }
  }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=0;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        int x=sum/2;
        
       int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
       return solve(arr,sum/2,n,dp);
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends