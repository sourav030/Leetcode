class Solution {
public:
    vector<vector<int>>dp;
    int solve(string word1,string word2, int n, int m){
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
            return dp[n][m]=solve(word1,word2,n-1,m-1);
        }
        else{
            return dp[n][m]=1+min({solve(word1,word2,n-1,m),solve(word1,word2,n-1,m-1),solve(word1,word2,n,m-1)});
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(word1,word2,n,m);
    }
};