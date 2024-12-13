//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int solve(int capacity, vector<int> &val, vector<int> &wt,int n,  vector<vector<int>> &dp){
        // harmara sabse chota input hai n=0 and capacity=0;
        // our uska valid output hai 0
        if(n==0 || capacity==0){
            return 0;
        }
        // abb hum item ko bag main tab dalenge jab uska weight capacity se kam ya equal hog
        
        if(dp[n][capacity]!=-1){
            return dp[n][capacity];
        }
        
        if(wt[n-1]<=capacity){
            // yaha pr do choice hai item ko le ya na le
            return dp[n][capacity]= max(val[n-1]+solve(capacity-wt[n-1],val,wt,n-1,dp),solve(capacity,val,wt,n-1,dp));
        }
        else {
            return dp[n][capacity]= solve(capacity,val,wt,n-1,dp);
        }
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n+1,vector<int>(capacity+1));
        
        // ye memoization wala code hai
        // int x= solve(capacity,val,wt,n,dp);
        // return x;
        
        // ye top to down wala
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<capacity+1; j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<capacity+1; j++){
                if(wt[i-1]<=j){
                    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][capacity];
        
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends