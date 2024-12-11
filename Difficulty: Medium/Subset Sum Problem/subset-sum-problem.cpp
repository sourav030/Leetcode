//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  bool solve(vector<int>& arr, int target,int n, vector<vector<int>> &dp){
      if(target==0){
          return 1;
      }
      if(n<=0 or target <0)
      {
          return 0;
      }
      if(dp[n][target]!=-1){
          return dp[n][target];
      }
      if(arr[n-1]>target){
           dp[n][target]=solve(arr,target,n-1,dp);
      }
      else{
          bool include=solve(arr,target-arr[n-1],n-1,dp);
          bool exclude=solve(arr,target,n-1,dp);
           dp[n][target]=include or exclude;
      }
      return dp[n][target];
     
  }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
          int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1)); // DP ko -1 se initialize karo
    return solve(arr, target, n, dp);
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends