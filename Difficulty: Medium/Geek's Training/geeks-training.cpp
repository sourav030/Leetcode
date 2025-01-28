//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<vector<int>>& arr, int n, int index,int prev,vector<vector<int>> &dp){
        if(index==n){
            return 0;
        }
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        int maxi=INT_MIN;
        for(int i=0; i<3; i++){
            if(i!=prev){
                maxi=max(maxi,arr[index][i]+solve(arr,n, index+1,i,dp));
            }
        }
        dp[index][prev+1]=maxi;
        return dp[index][prev+1];
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        int index=0;
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(arr,n, index,-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends