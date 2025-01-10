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

    void dfs(int row,int col, vector<vector<char>>& mat, vector<vector<int>>& visited){
        if(visited[row][col]){
            return;
        }
        visited[row][col]=1;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0; i<4; i++){
            int newrow=row+rows[i];
            int newcol=col+cols[i];
            if(newrow>=0 and newrow<n and newcol>=0 and newcol<m){
                if(!visited[newrow][newcol] and mat[newrow][newcol]=='O'){
                    dfs(newrow,newcol,mat,visited);
                }
            }

        }
    }

  
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
         int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>>visited(row,vector<int>(col,0));

        for(int i=0; i<col; i++){
            // check the first row
            if(mat[0][i]=='O' and !visited[0][i])
            {
                dfs(0,i,mat, visited);
            }

            // check the last row

            if(mat[row-1][i]=='O' and !visited[row-1][i] ){
                dfs(row-1,i,mat,visited);
            }
        }

        for(int i=0; i<row; i++){
            // check the first coloumn
            if(mat[i][0]=='O' and !visited[i][0]){
                dfs(i,0,mat,visited);
            }
            // check the last coloumns
            if(mat[i][col-1]=='O' and !visited[i][col-1]){
                dfs(i,col-1,mat,visited);
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j]=='O' and !visited[i][j]){
                    mat[i][j]='X';
                }
            }
        }
        
        return mat;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends