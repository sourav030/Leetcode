class Solution {
public:
    vector<vector<int>>dp;
    int solve(int n1,int n2,string &s1,string &s2){
        if(n1==0 || n2==0){
            return 0;
        }
        if(dp[n1][n2]!=-1){
            return dp[n1][n2];
        }
        if(s1[n1-1]==s2[n2-1]){
            return dp[n1][n2]=1+solve(n1-1,n2-1, s1,s2);
        }
        else{
            return dp[n1][n2]=max(solve(n1-1,n2,s1,s2),solve(n1,n2-1,s1,s2));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        string str1=s;
        reverse(str1.begin(),str1.end());
        return solve(n,n,s,str1);
    }
};