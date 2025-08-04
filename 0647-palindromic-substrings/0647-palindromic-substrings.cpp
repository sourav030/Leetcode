class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, string str){
       if(i>=j){
        return 1;
       }

       if(dp[i][j]!=-1){
        return dp[i][j];
       }
       if(str[i]==str[j]){
        return dp[i][j]=solve(i+1,j-1,str);
       }
       
       return  dp[i][j]=0;
    }
    int countSubstrings(string s) {
        int n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(solve(i,j,s)){
                    count++;
                }
            }
        }
        return count;
    }
};