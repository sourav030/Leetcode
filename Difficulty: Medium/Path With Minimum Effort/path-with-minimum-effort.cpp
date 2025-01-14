//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  

int MinimumEffort(int n, int m, vector<vector<int>> &heights) {
    // Priority queue to store {effort, {row, col}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Distance vector to store minimum effort to reach each cell
    vector<vector<int>> dis(n, vector<int>(m, 1e9));
    
    // Starting point effort is 0
    dis[0][0] = 0;
    pq.push({0, {0, 0}});
    
    // Directions for moving up, right, down, left
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        
        // If destination is reached, return the effort
        if (row == n - 1 && col == m - 1) 
            return diff;
        
        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int newr = row + dr[i];
            int newc = col + dc[i];
            
            // Check if the new cell is within bounds
            if (newr >= 0 && newr < n && newc >= 0 && newc < m) {
                // Calculate the new effort
                int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);
                
                // If the new effort is smaller, update and push to the queue
                if (newEffort < dis[newr][newc]) {
                    dis[newr][newc] = newEffort;
                    pq.push({newEffort, {newr, newc}});
                }
            }
        }
    }
    
    // In case no path is found (edge case)
    return 0;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends