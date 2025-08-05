class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, string &str){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(str[i]==str[j]){
            return dp[i][j]=solve(i+1,j-1,str);
        }
        else{
            return dp[i][j]=1+min(solve(i,j-1,str),solve(i+1,j,str));
        }
    }
    int minInsertions(string s) {
        int n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,s);
    }
};