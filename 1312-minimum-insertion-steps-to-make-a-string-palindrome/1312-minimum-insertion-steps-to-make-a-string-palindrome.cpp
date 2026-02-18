class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &s, int idx1, int idx2){
          if(idx1>=idx2){
            return 0;
          }
          if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
          }
          if(s[idx1]==s[idx2]){
              return dp[idx1][idx2]= solve(s,idx1+1,idx2-1);
          }
          else{
            return dp[idx1][idx2]= 1+min(solve(s,idx1+1,idx2),solve(s,idx1,idx2-1));
          }
    }
    int minInsertions(string s) {
         int idx=0;
         int n=s.length()-1;
         dp.assign(n+1,vector<int>(n+1,-1));
         return solve(s,idx,n);
    }
};