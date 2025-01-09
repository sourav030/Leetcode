//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(); 
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        
        
        int rows[4]={1,0,-1,0};
        int cols[4]={0,1,0,-1};
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step=q.front().second;
            dist[row][col]=step;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow=row+rows[i];
                int ncol=col+cols[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and visited[nrow][ncol]==0){
                    q.push({{nrow,ncol},step+1});
                    visited[nrow][ncol]=1;
                }
            }
            
        }
        return dist;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends