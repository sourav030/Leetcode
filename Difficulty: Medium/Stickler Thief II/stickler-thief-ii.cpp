//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr, int index, int n,vector<int>&dp){
        if(index>n) return 0;
        if(dp[index]!=-1) return dp[index];
        return dp[index]= max(arr[index]+solve(arr,index+2,n,dp),solve(arr,index+1,n,dp));
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size()-1;
        vector<int>dp(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(solve(arr,0,n-1,dp),solve(arr,1,n,dp2));
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends