class Solution {
public:
    int solve(int index, string s, int n, vector<int>&dp){
        if(index == n) {
            return 1;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        if(s[index] == '0'){
            return dp[index]=0;;
        }

        int result = solve(index + 1, s, n,dp); 

        if(index + 1 < n){
            if((s[index] == '1') || (s[index] == '2' && s[index + 1] <= '6')){
                result += solve(index + 2, s, n,dp); 
            }
        }
        return dp[index]= result;
    }

    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
        int n = s.length();
        return solve(0, s, n,dp);
    }
};
