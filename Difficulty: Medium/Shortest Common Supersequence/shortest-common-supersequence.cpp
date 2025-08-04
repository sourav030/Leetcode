// User function template for C++

class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings.
    vector<vector<int>>dp;
    int solve(string &s1,string &s2, int n1, int n2){
        if(n1<=0 or n2<=0){
            return 0;
        }
        if(dp[n1][n2]!=-1){
           return dp[n1][n2];
        }
        if(s1[n1-1]==s2[n2-1]){
            return dp[n1][n2]=1+solve(s1,s2,n1-1,n2-1);
        }
        else{
            return dp[n1][n2]=max(solve(s1,s2,n1,n2-1),solve(s1,s2,n1-1,n2));
        }
    }
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        int n1=s1.length();
        int n2=s2.length();
        
        dp.resize(n1+1,vector<int>(n2+1,-1));
        int x=solve(s1,s2,n1,n2);
        return (n1-x)+(n2-x)+x;
        
    }
};