//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr, int index, int n, int prevIndex,vector<vector<int>>&dp) {
    if (index == n) return 0;
    
    if(dp[index][prevIndex+1]!=-1){
        return dp[index][prevIndex+1];
    }
    // Exclude current element
    int exclude = solve(arr, index + 1, n, prevIndex,dp);

    // Include current element if it maintains increasing order
    int include = 0;
    if (prevIndex == -1 || arr[index] > arr[prevIndex]) {
        include = 1 + solve(arr, index + 1, n, index,dp);
    }

     dp[index][prevIndex+1]= max(include, exclude);
    return dp[index][prevIndex+1];
}

int lis(vector<int>& arr) {
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solve(arr, 0,n, -1,dp);
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends