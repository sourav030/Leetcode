//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
   vector<int> nthRowOfPascalTriangle(int n) {
    const int MOD = 1e9 + 7;
    vector<int> row;
    long long val = 1;
    row.push_back(1); // First value is always 1
    
    for (int k = 1; k < n; ++k) {
        val = val * (n - k);
        val = val / k;
        val = val % MOD;
        row.push_back((int)val);
    }
    
    return row;
}

};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends