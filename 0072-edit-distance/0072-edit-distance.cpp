class Solution {
public:
    vector<vector<int>>dp;
    int solve(int n, int m, string word1,string word2){
        if(n==0){
            return m;
        }
        if(m==0){
            return n;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(word1[n-1]==word2[m-1]){
            return dp[n][m]=solve(n-1,m-1,word1,word2);
        }
        else{
            return dp[n][m]=1+min(
                {
                solve(n,m-1,word1,word2), // insert opertaion perform
                solve(n-1,m,word1,word2), // delete operation perform
                solve(n-1,m-1,word1,word2) // replace opertion perform
            }
            );
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        // dp.resize(n+1,vector<int>(m+1,-1));
        // return solve(n,m,word1,word2);
        // agar hum isko ko bottom up main convert kre
        vector<vector<int>>arr(n+1,vector<int>(m+1,0));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 or j==0){
                    arr[i][j]=i+j;
                }
                else if(word1[i-1]==word2[j-1]){
                    arr[i][j]=arr[i-1][j-1];
                }
                else{
                    arr[i][j]=1+min({arr[i-1][j-1],arr[i-1][j],arr[i][j-1]});
                }
            }
        }
        return arr[n][m];
    }
};