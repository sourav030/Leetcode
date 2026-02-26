class Solution {
public:
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    int orangesRotting(vector<vector<int>>& grid) {
         int n=grid.size();
         int m=grid[0].size();
         int freshOrange=0;
         queue<pair<int,int>>q;
         for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    freshOrange++;
                }
            }
         }

         int time=0;
      
         while(!q.empty()){
            int n1=q.size();
            bool infected=0;
            for(int i=1; i<=n1; i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int n_r=r+dx[i];
                    int n_c=c+dy[i];
                    if(n_r>=0 and n_r<n and n_c>=0 and n_c<m){
                        if(grid[n_r][n_c]==1){
                            freshOrange--;
                            infected=1;
                            grid[n_r][n_c]=2;
                            q.push({n_r,n_c});
                        }
                    }
                }
            }
            if(infected)
            time++;
         }

         return freshOrange==0?time:-1;


    }
};