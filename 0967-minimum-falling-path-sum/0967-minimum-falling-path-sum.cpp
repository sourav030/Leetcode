class Solution {
public:
    int n;
    int solve(vector<vector<int>>& matrix , int row, int col,vector<vector<int>>&dp){
        if(row==n-1){
            return matrix[row][col];
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int sum=matrix[row][col];
        int mini=INT_MAX;
        if( col-1>=0){
            mini=min(mini,sum+solve(matrix,row+1, col-1,dp));
        }
     
            mini=min(mini,sum+solve(matrix,row+1,col,dp));
    
        if( col+1<n){
            mini=min(mini,sum+solve(matrix,row+1,col+1,dp));
        }
        return dp[row][col]= mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {

/*---------------------------------TOP DOWN DP APPROCH----------- ---------------------*/
        // int result=INT_MAX;
        // n=matrix.size();
        // int row=0;
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // for(int col=0; col<n; col++){
        //     result=min(result,solve(matrix,row,col,dp));
        // }
        // return result;
 /*---------------------------------CODE THAT DOES NOT GIVE TLE----------- ---------------------*/   
        int n = matrix.size();
        vector<vector<int>> dp = matrix;  

        for (int i = n - 2; i >= 0; i--) {  
            for (int j = 0; j < n; j++) {
                int sameCol = (i+1 < n) ? dp[i+1][j] : INT_MAX; 

                if (j+1 < n && i+1 < n) sameCol = min(sameCol, dp[i+1][j+1]); 
                if (j-1 >= 0 && i+1 < n) sameCol = min(sameCol, dp[i+1][j-1]); 
                dp[i][j] = matrix[i][j] + sameCol; 
            }
        }

        return *min_element(dp[0].begin(), dp[0].end()); 

    }
};