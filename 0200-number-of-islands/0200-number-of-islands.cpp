class Solution {
public:

    vector<int>row={0,0,1,-1};
    vector<int>col={1,-1,0,0};
    void dfs(vector<vector<bool>>&visited, vector<vector<char>>&grid, int r, int c){
        visited[r][c]=true;
        for(int i=0; i<4; i++){
            int new_r=r+row[i];
            int new_c=c+col[i];
            if(new_r>=0 and new_r<visited.size() and new_c>=0 and new_c<visited[0].size()){
                if(!visited[new_r][new_c] and grid[new_r][new_c]=='1'){
                    dfs(visited,grid,new_r,new_c);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,0));
        int count=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(!visited[i][j] and grid[i][j]=='1'){
                    count++;
                    dfs(visited,grid, i,j);
                }
            }
        }
        return count;
    }
};