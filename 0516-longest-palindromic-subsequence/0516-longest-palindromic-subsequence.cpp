class Solution {
    int find(int n, int m, string &a,string &b,vector<vector<int>> &dp){
        if(n<=0 or m<=0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(a[n-1]==b[m-1]){
            return dp[n][m]= 1+find(n-1,m-1,a,b,dp);
        }
        else{
            return dp[n][m]=max(find(n-1,m,a,b,dp),find(n,m-1,a,b,dp));
        }
    }
public:
    int longestPalindromeSubseq(string s) {
        string a=s;
        string b=a;
        int n=a.size();
        int m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        reverse(b.begin(),b.end());
        return find(a.size(),b.size(),a,b,dp);
    }
};