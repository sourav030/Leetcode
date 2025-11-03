class Solution {
public:
    void rowZero(vector<vector<int>>&matrix,int r){
        for(int i=0; i<matrix[0].size(); i++){
            matrix[r][i]=0;
        }
    }
    void colZero(vector<vector<int>>&matrix, int c){
        for(int i=0; i<matrix.size(); i++){
            matrix[i][c]=0;
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