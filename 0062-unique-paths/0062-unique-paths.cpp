class Solution {
public:
    vector<vector<int>>grid;
    vector<vector<int>>dp;
    vector<int>row={1,0};
    vector<int>col={0,1};
    int solve(int r, int c, int m, int n){
        if(r==m-1 and c==n-1){
            return 1;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int count=0;
        grid[r][c]=1;
        for(int i=0; i<2; i++){
            int rows=r+row[i];
            int cols=c+col[i];
            if(rows>=0 and rows<m and cols>=0 and cols<n and !grid[rows][cols]){
                count+=solve(rows,cols,m,n);
            }
        }
        grid[r][c]=0;
        return dp[r][c]= count;

    }
    int uniquePaths(int m, int n) {
        grid.assign(m,vector<int>(n,0));
        dp.assign(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n);
    }
};