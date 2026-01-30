class Solution {
public:
    void rowZero(vector<vector<int>>&matrix, int r){
        int len=matrix[0].size();
        for(int i=0; i<len; i++){
            matrix[r][i]=0;
        }
        return;
    }
    void colZero(vector<vector<int>>&matrix, int col){
        int len=matrix.size();
        for(int i=0; i<len; i++){
            matrix[i][col]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>row;
        vector<int>col;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int i=0; i<row.size(); i++){
            rowZero(matrix,row[i]);
        }
        for(int i=0; i<col.size(); i++){
            colZero(matrix,col[i]);
        }
    }
};