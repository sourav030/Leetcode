//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr, int index,vector<int> &dp){
        if(index>=arr.size()) return 0;
        if(dp[index]!=-1)return dp[index];
        return dp[index]= max(arr[index]+solve(arr,index+2,dp),solve(arr,index+1,dp));
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(arr,0,dp);
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
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends