//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // code here
         int n = arr.size();
    
    // If there is only one tower, the difference is always 0
    if (n == 1) return 0;

    // Sort the array
    sort(arr.begin(), arr.end());
    
    // Initialize the result to a large number
    int result = arr[n-1] - arr[0];
    
    // Consider modifying the smallest and largest tower by k
    for (int i = 1; i < n; i++) {
        int smallest = min(arr[0] + k, arr[i] - k);
        int largest = max(arr[n-1] - k, arr[i-1] + k);
        
        result = min(result, largest - smallest);
    }
    
    return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends