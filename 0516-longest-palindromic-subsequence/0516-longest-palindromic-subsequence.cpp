class Solution {
public:
    vector<vector<int>>dp;
    int solve(string s1, string s2, int idx, int idx2){
        if(idx==0 or idx2==0){
            return 0;
        }
        if(dp[idx][idx2]!=-1){
            return dp[idx][idx2];
        }
        if(s1[idx-1]==s2[idx2-1]){
            return dp[idx][idx2]=1+solve(s1,s2,idx-1, idx2-1);
        }
        else{
            return dp[idx][idx2]= max(solve(s1,s2,idx-1,idx2), solve(s1,s2,idx,idx2-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        dp.assign(n+1,vector<int>(n+1,0));
        string str=s;
        reverse(s.begin(),s.end());
        // return solve(str,s,n,n);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==str[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};