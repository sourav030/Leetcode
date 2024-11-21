//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int maximumProfit(vector<int> &prices) {
    int n = prices.size();
    int max_profit = 0;

    // Traverse through the prices array
    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
            // If there is a profit to be made, add the difference to the total profit
            max_profit += prices[i] - prices[i - 1];
        }
    }

    return max_profit;
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
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends