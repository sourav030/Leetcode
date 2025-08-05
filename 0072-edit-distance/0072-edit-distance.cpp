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
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(n,m,word1,word2);
    }
};