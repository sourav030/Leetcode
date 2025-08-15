class Solution {
public:
    vector<vector<int>>dp;
    int Solve(string &str, int start, int end){
        if(start>=end){
            return true;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        if(str[start]==str[end]){
            return dp[start][end]= Solve(str,start+1,end-1);
        }
        return dp[start][end]= false;
    }
    string longestPalindrome(string s) {
        int start=0;
        int len=0;
        int n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));

        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(Solve(s,i,j)){
                    if(j-i+1>len){
                        start=i;
                        len=j-i+1;
                    }
                }
            }
        }

        return s.substr(start,len);
    }
};