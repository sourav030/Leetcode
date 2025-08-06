class Solution {
public:
    vector<vector<int>>dp;
    int solve(int start,int end, string &str){
        if(start>=end){
            return true;
        }
        if(str[start]==str[end]){
           return  dp[start][end]=solve(start+1,end-1,str);
        }
        else{
           return dp[start][end]=0;
        }
    }
    string longestPalindrome(string s) {
        int n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        int start=0;
        int len=0;

        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(solve(i,j,s)){
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