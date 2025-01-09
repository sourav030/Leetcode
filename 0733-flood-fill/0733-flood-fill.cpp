class Solution {
    int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};
    void DFS(vector<vector<int>>& image, int sr, int sc, int color, int old){
        image[sr][sc]=color;
          int n=image.size(); // y row hai
        int m=image[0].size(); // y coloumn hai

        for(int i=0; i<4; i++){
            if(sr+row[i]>=0 and sr+row[i]<n and sc+col[i]>=0 and sc+col[i]<m and image[sr+row[i]][sc+col[i]]==old)
            {
                DFS(image,sr+row[i],sc+col[i],color,old);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(); // y row hai
        int m=image[0].size(); // y coloumn hai
        
        
        int old=image[sr][sc];
        if (old == color) return image;
        DFS(image,sr,sc,color,old);
        return image;

    }
};