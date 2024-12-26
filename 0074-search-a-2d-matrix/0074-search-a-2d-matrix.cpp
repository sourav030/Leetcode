class Solution {
public:
    bool solve(vector<vector<int>>& mat, int midd,int target){
        
        int start=0;
        int end=mat[midd].size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mat[midd][mid]==target){
                return true;
            }
            else if (mat[midd][mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {

            if (mat.empty() || mat[0].empty()) {
            return false; // Handle empty matrix or empty rows
        }
        int row=mat.size();
        int col=mat[0].size();
        int start=0;
        int end=row-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(target>=mat[mid][0] && target<=mat[mid][col-1]){
                return solve(mat,mid,target);
            }
            else if (target >mat[mid][col-1]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};