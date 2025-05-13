//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isValid(vector<vector<int>>& mat) {
    unordered_set<string> st;
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int val = mat[i][j];
            if (val == 0) continue;

            string row = "row" + to_string(i) + "-" + to_string(val);
            string col = "col" + to_string(j) + "-" + to_string(val);
            int boxNum = (i / 3) * 3 + (j / 3);
            string box = "box" + to_string(boxNum) + "-" + to_string(val);

            if (st.count(row) || st.count(col) || st.count(box)) {
                return false;
            }

            st.insert(row);
            st.insert(col);
            st.insert(box);
        }
    }

    return true;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for (int i = 0; i < 81; i++)
            cin >> mat[i / 9][i % 9];

        Solution obj;
        bool res = obj.isValid(mat);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends