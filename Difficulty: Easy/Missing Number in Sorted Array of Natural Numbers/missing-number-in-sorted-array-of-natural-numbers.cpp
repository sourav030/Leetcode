//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        // Code here
        int n=arr.size();
        n+=1;
        int sum=n*(n+1)/2;
        
        int sum1=0;
        for(int i=0; i<arr.size(); i++){
            sum1+=arr[i];
        }
        return sum-sum1;
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.missingNumber(arr);
        cout << ans << endl;
        // cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends