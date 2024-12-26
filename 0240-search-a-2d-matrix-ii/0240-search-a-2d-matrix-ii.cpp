class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row=mat.size();
        int col=mat[0].size();
        int i=0;
        int j=col-1;
        while(i<row and j>=0){

            if(mat[i][j]==target){
                return 1;
            }
            else if (mat[i][j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return 0;
    }
};