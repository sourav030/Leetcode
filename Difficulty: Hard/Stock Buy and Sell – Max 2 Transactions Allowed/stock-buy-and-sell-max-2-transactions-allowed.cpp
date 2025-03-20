//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   
    int solve(vector<int> &prices, int index, int buy, int k, vector<vector<vector<int>>>&dp){
        if(index>=prices.size() or k==0) return 0;
        if(dp[index][buy][k]!=-1) return dp[index][buy][k];
        int include=0;
        int exclude=0;
        if(buy){
            include=-prices[index]+solve(prices,index+1,0,k,dp);
            exclude=solve(prices,index+1,1,k,dp);
            return dp[index][buy][k] =max(include,exclude);
        }
        else{
            include=prices[index]+solve(prices,index+1,1,k-1,dp);
            exclude=solve(prices,index+1,0,k,dp);
            return dp[index][buy][k]=max(include,exclude);
        }
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(3,-1)));
        int buy=1;
        return solve(prices,0,buy,2,dp);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends