class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
       
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        
        int time = 0;
        
      
        while(!q.empty() && fresh > 0) {
            int n = q.size();
            while(n--) {
                auto [r, c] = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int nr = r + dx[i];
                    int nc = c + dy[i];
                    
                    if(nr >= 0 && nr < row && nc >= 0 && nc < col 
                       && grid[nr][nc] == 1) {
                        
                        grid[nr][nc] = 2; 
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            time++;
        }
        
       
        if(fresh > 0) return -1;
        return time;
    }
};
