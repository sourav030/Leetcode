//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution {
    public:
    vector<int>rows={-1,1,0,0};
    vector<int>cols={0,0,-1,1};
    int N;
    int M;
    
    void dfs(vector<vector<int>>& matrix,vector<vector<int>>&visited, int row, int col){
        
        if(row>=N or col>=M or row<0 or col<0) return;
        if (visited[row][col] || matrix[row][col] == 0) return;

        visited[row][col]=1;
        
        for(int i=0; i<4; i++){
            int new_row=row+rows[i];
            int new_col=col+cols[i];
            if(new_row>=0 and new_row<N and new_col>=0 and new_col<M and !visited[new_row][new_col]){
                dfs(matrix,visited,new_row,new_col);
            }
        }
        
    }
    
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        // Code here
        N=n;
        M=m;
        
        vector<vector<int>>visited(N,vector<int>(M,0));
        // Traversing the first and last row of matrix
        for(int i=0; i<M; i++){
            if(matrix[0][i]==1 and !visited[0][i]) dfs(matrix,visited,0,i);
            if(matrix[N-1][i]==1 and !visited[N-1][i]) dfs(matrix,visited,N-1,i);
        }
        
        // Traverse the left and right coloumn of matrix;
        
        for(int i=0; i<N; i++){
            if(matrix[i][0]==1 and !visited[i][0]) dfs(matrix,visited,i,0);
            if(matrix[i][M-1]==1 and !visited[i][M-1]) dfs(matrix,visited,i,M-1);
        }
        
        //  count the island
        int count=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(matrix[i][j]==1 and !visited[i][j]){
                    dfs(matrix,visited, i, j);
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
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
	
	return 0;
	
}


// } Driver Code Ends