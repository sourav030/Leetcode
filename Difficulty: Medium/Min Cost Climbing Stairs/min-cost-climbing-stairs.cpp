//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int>&cost,int index, vector<int>&dp){
        if(index>=cost.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int include=cost[index]+solve(cost,index+1,dp);
        int exclude = (index + 1 < cost.size() ? cost[index + 1] : 0) + solve(cost, index + 2,dp); 
        return dp[index]= min(include,exclude);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        vector<int>dp(cost.size()+1,-1);
        return solve(cost,0,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends