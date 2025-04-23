//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Function to find all combinations of elements
    // in array arr that sum to target.
    vector<vector<int>>result;
    void solve(vector<int>&arr, int target, int n, int index, vector<int>ans){
        if(target==0){
            result.push_back(ans);
            return;
        }
        if(index>n){
            return ;
        }
        if(arr[index]<=target){
            ans.push_back(arr[index]);
            solve(arr,target-arr[index], n, index,ans);
            ans.pop_back();
        }
        solve(arr,target,n,index+1,ans);
    }
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        // Your code here
        int n=arr.size()-1;
        vector<int>ans;
        solve(arr,target,n,0,ans);
        return result;
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
        vector<vector<int>> ans = ob.combinationSum(arr, sum);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                sort(ans[i].begin(), ans[i].end());
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends