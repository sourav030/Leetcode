class Solution {
public:
    int solve(string s, int index, int prev_val,vector<vector<int>>&dp){
        if(index>=s.length()) return 0;
        if(dp[index][prev_val]!=-1) return dp[index][prev_val];
        int flip=INT_MAX;
        int Non_flip=INT_MAX;
        if(s[index]=='0'){
            if(prev_val==0){
                flip=1+solve(s,index+1,1,dp);
                Non_flip=solve(s,index+1,0,dp);
            }
            else{
               Non_flip=1+solve(s,index+1,1,dp);
            }
        }
        else if(s[index]=='1'){
            if(prev_val==0){
                flip=1+solve(s,index+1,0,dp);
                Non_flip=solve(s,index+1,1,dp);
            }
            else{
                Non_flip=solve(s,index+1,1,dp);
            }
        }
        return dp[index][prev_val]= min(flip,Non_flip);
    }
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0); // dp[i] = min flips needed for s[0...i-1]
        int ones = 0; // Count of '1's encountered so far

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') {
                ones++;
                dp[i] = dp[i - 1];  // No need to flip, carry forward previous state
            } else {
                dp[i] = min(dp[i - 1] + 1, ones); // Flip '0' OR turn previous '1's into '0'
            }
        }
        return dp[n];
        
    }
};