//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(int c, int n, vector<vector<int>> &ans, vector<int> &board, 
           vector<bool> &columns, vector<bool> &ldiag, vector<bool> &rdiag) {
    if (c == n) {
        ans.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!columns[i] && !ldiag[c - i + n - 1] && !rdiag[i + c]) {
            board.push_back(i + 1);
            columns[i] = true;
            ldiag[c - i + n - 1] = true;
            rdiag[i + c] = true;
            
            solve(c + 1, n, ans, board, columns, ldiag, rdiag);
            
            board.pop_back();
            columns[i] = false;
            ldiag[c - i + n - 1] = false;
            rdiag[i + c] = false;
        }
    }
}

vector<vector<int>> nQueen(int n) {
    vector<vector<int>> ans;
    vector<bool> columns(n, false);
    vector<bool> ldiag(2 * n - 1, false);
    vector<bool> rdiag(2 * n - 1, false);
    vector<int> board;
    
    solve(0, n, ans, board, columns, ldiag, rdiag);
    return ans;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends