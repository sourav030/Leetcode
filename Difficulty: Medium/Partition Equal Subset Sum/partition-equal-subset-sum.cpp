//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    bool solve(vector<int>& arr,int sum, int n,vector<vector<int>>&dp){
        if(sum==0)return 1;
        if(n<=0)return 0;
        bool include=0;
        bool exclude=0;
        if(dp[n][sum]!=-1) return dp[n][sum];
        if(sum<arr[n-1]){
            exclude=solve(arr,sum,n-1,dp);
        }
        else{
            include=solve(arr,sum-arr[n-1],n-1,dp);
            exclude=solve(arr,sum,n-1,dp);
        }
        return dp[n][sum]= include||exclude;
    }
    
    int SumofArray(vector<int>& arr){
        int sum=0;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
        }
        return sum;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=SumofArray(arr);
        if(sum%2!=0) return false;
        int n=arr.size();
        int m=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
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