//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int rows[4]={1,0,-1,0};
    int cols[4]={0,1,0,-1};

    void DFS(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited){
        if(visited[row][col]){
            return;
        }
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        for(int i=0; i<4; i++){
            int newrow=row+rows[i];
            int newcol=col+cols[i];
            
            if(newrow>=0 and newrow<n and newcol>=0 and newcol<m){
                 if(grid[newrow][newcol]==1 and !visited[newrow][newcol]){
                 DFS(newrow,newcol,grid,visited);
            }
            }
        }

    }

    int numberOfEnclaves(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> visited(row,vector<int>(col));

        for(int i=0; i<col; i++){
            // check the first row
            if(grid[0][i]==1 and !visited[0][i]){
                DFS(0,i,grid,visited);
            }
            // check the last row
            if(grid[row-1][i]==1 and !visited[row-1][i]){
                DFS(row-1,i,grid,visited);
            }
        }

        // Now we check the first coloumn and last coloumn

        for(int i=0; i<row; i++){
            // now we check the first coloum
            if(grid[i][0]==1 and !visited[i][0]){
                DFS(i,0,grid,visited);
            }

            // now we check the last coloum
            if(grid[i][col-1]==1 and !visited[i][col-1]){
                DFS(i,col-1,grid,visited);
            }
        }

        // here we count the one
        int count=0;
        for(int i=0; i<row;  i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1 and !visited[i][j]){
                    count++;
                }
            }
        }

        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends