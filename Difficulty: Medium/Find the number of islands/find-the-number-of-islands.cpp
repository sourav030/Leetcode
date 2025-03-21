//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to find the number of islands.
    int n;
    int m;
    vector<int> rows = {-1, 1, 0, 0, -1, -1, 1, 1};
    vector<int> cols = {0, 0, -1, 1, -1, 1, -1, 1};
    void dfs( vector<vector<bool>> &visited, vector<vector<char>>& grid, int row, int col  ){
        if(row>=n or col>=m or row<0 or col<0) return;
        if(grid[row][col]=='0' or visited[row][col]) return;
        visited[row][col]=1;
        
        for(int i=0; i<8; i++){
            int new_row=row+rows[i];
            int new_col=col+cols[i];
             if (new_row >= 0 && new_col >= 0 && new_row < n && new_col < m) {
                if (!visited[new_row][new_col]) {
                    dfs(visited, grid, new_row, new_col);
                }
            }
        }
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
         n=grid.size();
         m=grid[0].size();
        
        int count =0;
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
             if(grid[i][j]=='1' and !visited[i][j]){
                 dfs(visited,grid,i,j);
                 count++;
             }   
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends