class Solution {
public:
    vector<vector<int>>dp;
    int palindrome(string &str, int start, int end){
        if(start>=end){
            return 1;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        if(str[start]!=str[end]){
            return 0;
        }
        dp[start][end]=palindrome(str, start+1, end-1);
        return dp[start][end];
    }
    string longestPalindrome(string s) {
        if(s.length()==0){
            return " ";
        }
        int n=s.length();
        int start=0;
        int len=1;
        
        dp.assign(n,vector<int>(n,-1));

        for(int i=0; i<s.length(); i++){
            for(int j=i+1; j<s.length(); j++){
                if(palindrome(s,i,j)){
                    int l=j-i+1;
                    if(l>len){
                        start=i;
                        len=l;
                    }
                }
            }
        }
        return s.substr(start,len);

    }
};