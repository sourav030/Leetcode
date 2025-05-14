//{ Driver Code Starts
// Initial Template for C++
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;


// } Driver Code Ends

// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static string magicSquare(vector<vector<int>>& mat) {
        int n = mat.size();
        int square = n * n;
        
        map<int, int> mp;
        int rowSum = 0, colSum = 0;
        int diag1 = 0, diag2 = 0;

        for (int i = 0; i < n; i++) {
            int rowSumTemp = 0, colSumTemp = 0;
            for (int j = 0; j < n; j++) {
                if (mp.find(mat[i][j]) != mp.end()) {
                    return "Not a Magic Square";
                }
                if (mat[i][j] < 1 || mat[i][j] > square) {
                    return "Not a Magic Square";
                }
                mp[mat[i][j]] = 1;

                rowSumTemp += mat[i][j];
                colSumTemp += mat[j][i];
                
                if (i == j) {
                    diag1 += mat[i][j];
                }
                if (i + j == n - 1) {
                    diag2 += mat[i][j];
                }
            }

            if (i == 0) {
                rowSum = rowSumTemp;
                colSum = colSumTemp;
            } else {
                if (rowSum != rowSumTemp || colSum != colSumTemp) {
                    return "Not a Magic Square";
                }
            }
        }

        if (rowSum != diag1 || rowSum != diag2) {
            return "Not a Magic Square";
        }

        return "Magic Square";
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc-- > 0) {
        int n;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        Solution sol;
        cout << sol.magicSquare(mat) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends