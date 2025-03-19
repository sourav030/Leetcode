//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& prices, int k, int n, int buy,vector<vector<vector<int>>>&dp){
        if(n>=prices.size() or k==0)return 0;
        int include=0;
        int exclude=0;
        if(dp[n][buy][k]!=-1){
            return dp[n][buy][k];
        }
        if(buy){
            include=-prices[n]+solve(prices,k,n+1,0,dp);
            exclude=solve(prices,k,n+1,1,dp);
            dp[n][buy][k]= max(include,exclude);
        }
        else{
            include=prices[n]+solve(prices,k-1,n+1,1,dp);
            exclude=solve(prices,k,n+1,0,dp);
            dp[n][buy][k]= max(include,exclude);
        }
        return dp[n][buy][k];
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int buy=1;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(k+1,-1)));
        return solve(prices,k,0,buy,dp);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends