//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(vector<int>&arr,int sum, int index,vector<vector<int>>&dp){
        if(sum==0)return true;
        if(index>=arr.size()){
            return false;
        }
        if(dp[index][sum]!=-1) return dp[index][sum];
        bool include=0;
        bool exclude=0;
        if(sum<arr[index]) exclude=solve(arr,sum,index+1,dp);
        else{
            include=solve(arr,sum-arr[index],index+1,dp);
            exclude=solve(arr,sum,index+1,dp);
        }
        return dp[index][sum]=include||exclude;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        return solve(arr,sum,0,dp);
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