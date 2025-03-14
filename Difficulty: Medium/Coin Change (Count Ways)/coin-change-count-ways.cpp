//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& coins,int sum,int index,vector<vector<int>>&dp){
        if(sum==0) return 1;
        if(index>=coins.size() or sum<0) return 0;
        if(dp[index][sum]!=-1) return dp[index][sum];
        int include=0;
        int exclude=0;
        if(coins[index]>sum){
            exclude=solve(coins,sum,index+1,dp);
        }
        else{
            include=solve(coins,sum-coins[index],index,dp);
            exclude=solve(coins,sum,index+1,dp);
        }
        return dp[index][sum]= include+exclude;
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        vector<vector<int>>dp(coins.size()+1,vector<int>(sum+1,-1));
        return solve(coins,sum,0,dp);
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