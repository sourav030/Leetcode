//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution {
public:
    int row[4] = {1, -1, 0, 0};  // Direction vectors for moving up, down, left, right
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j, int n, int m, vector<vector<int>>& A) {
        return i >= 0 && i < n && j >= 0 && j < m && A[i][j] == 1;
    }

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if (A[0][0] == 0) return -1;
        if (X == 0 && Y == 0) return 0;

        // Queue with preferred format {i, j, step}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});  // Starting at (0,0) with 0 steps
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        visited[0][0] = true;

        while (!q.empty()) {
            int i = q.front().first;          // i as the first element
            int j = q.front().second.first;   // j as the second element
            int step = q.front().second.second;  // step as the second pair’s second element
            q.pop();

            for (int k = 0; k < 4; k++) {
                int new_i = i + row[k];
                int new_j = j + col[k];

                if (new_i == X && new_j == Y && valid(new_i, new_j, N, M, A)) {
                    return step + 1;
                }

                if (valid(new_i, new_j, N, M, A) && !visited[new_i][new_j]) {
                    visited[new_i][new_j] = true;
                    q.push({new_i, {new_j, step + 1}});  // Use format with step as third element
                }
            }
        }

        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends