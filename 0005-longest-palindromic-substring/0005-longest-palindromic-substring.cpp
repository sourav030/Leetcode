class Solution {
public:
    vector<vector<int>>dp;
    int palindrome(int start, int end, string &s){
        if(start>=end){
            return 1;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        if(s[start]==s[end]){
            dp[start][end]=palindrome(start+1,end-1,s);
        }
        else{
            dp[start][end]=0;
        }
        return dp[start][end];
    }
    string longestPalindrome(string s) {
        int n=s.length();
        dp.assign(n, vector<int>(n, -1));

        int start=0;
        int end=0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(palindrome(i,j,s) and (j-i+1)>(end-start+1)){
                    start=i;
                    end=j;
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};