class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.length();
        int n2=str2.length();

        vector<vector<int>>dp(n1+1,vector<int>(n2+1));

        for(int i=0; i<=n1; i++){
            for(int j=0; j<=n2; j++){
                if(i==0 or j==0){
                    dp[i][j]=i+j;
                }
                else if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int i=n1;
        int j=n2;
        string scs="";

        while(i>0 and j>0){
            if(str1[i-1]==str2[j-1]){
                scs+=str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]<dp[i][j-1]){
                    scs+=str1[i-1];
                    i--;
                }
                else{
                    scs+=str2[j-1];
                    j--;
                }
            }
        }

        while(i>0){
            scs+=str1[i-1];
            i--;
        }

        while(j>0){
            scs+=str2[j-1];
            j--;
        }

        reverse(scs.begin(),scs.end());
        return scs;
    }
};