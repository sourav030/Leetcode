//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 

int rows[4] = {0, 1, 0, -1};
int cols[4] = {1, 0, -1, 0};

bool solve(int index, int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &mat, string &word) {
    if (index == word.length()) {
        return true;
    }

    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int ni = i + rows[k];
        int nj = j + cols[k];

        if (ni >= 0 && ni < mat.size() && nj >= 0 && nj < mat[0].size() && 
            !visited[ni][nj] && mat[ni][nj] == word[index]) {
            
            if (solve(index + 1, ni, nj, visited, mat, word)) {
                return true;
            }
        }
    }

    visited[i][j] = false; 
    return false;
}

bool isWordExist(vector<vector<char>> &mat, string &word) {
    int row = mat.size();
    int col = mat[0].size();
    
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == word[0]) {
                if (solve(1, i, j, visited, mat, word)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends