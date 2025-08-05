class Solution {
public:
    vector<vector<int>>dp;
    int solve(int n, int m, string &s, string &str){
        if(n<=0){
            return m;
        }
        if(m<=0){
            return n;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s[n-1]==str[m-1]){
            return dp[n][m]= solve(n-1,m-1,s,str);
        }
        else{
            return dp[n][m]=1+min(solve(n-1,m,s,str),solve(n,m-1,s,str));
        }
    }
    int minInsertions(string s) {
        int n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        string s1=s;
        reverse(s1.begin(), s1.end()); 
        return solve(n,n,s,s1)/2;

    }
};